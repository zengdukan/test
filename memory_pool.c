#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const int ADDR_ALIGNMENT = (8 - 1);
static void* align(void* addr) {
    return (void*)(((long)addr + ADDR_ALIGNMENT) & ~ADDR_ALIGNMENT);
}

#define align_int(addr) (((addr) + ADDR_ALIGNMENT) & ~ADDR_ALIGNMENT)

/*
| size | next | memory  |
{          size         }
 */
typedef struct block_s {
    uint32_t _size;
    struct block_s* _next;
    uint8_t addr[0];
} block_t;

static const int32_t BLOCK_SIZE = align_int(sizeof(block_t));

/*
| block head | block0 block1                    | block tail |
|                          AllMem                            |
*/
typedef struct pool_s {
    block_t _head;
    block_t* _tail;
    uint32_t _size;
} pool_t;

static uint8_t AllMem[1024 * 1024] = {0};

static pool_t pool = {
    ._tail = NULL,
    ._size = sizeof(AllMem),
};

void init_pool() {
    uint8_t* block_addr = AllMem + BLOCK_SIZE;
    block_t* block = (block_t*)align(block_addr);

    block_t* tail = (block_t*)(AllMem + sizeof(AllMem) - BLOCK_SIZE);
    tail->_size = BLOCK_SIZE;
    tail->_next = NULL;

    block->_size = (long)tail - (long)block;
    block->_next = tail;

    pool._tail = tail;
    pool._head._size = BLOCK_SIZE;
    pool._head._next = block;
    pool._size = block->_size;
}

void* pool_malloc(uint32_t size) {
    uint32_t need_size = align_int(size + BLOCK_SIZE);
    if (pool._size < need_size) {
        return NULL;
    }

    block_t* pre = &pool._head;
    block_t* cur = pre->_next;
    while (cur != pool._tail) {
        if (cur->_size >= need_size) {
            break;
        }

        pre = cur;
        cur = cur->_next;
    }

    if (cur == pool._tail) {
        return NULL;
    }


    uint32_t left_size = cur->_size - need_size;
    if (left_size > BLOCK_SIZE * 2) {
        block_t* new_block = (block_t*)((void*)cur + need_size);
        new_block->_size = cur->_size - need_size;
        new_block->_next = cur->_next;
        pre->_next = new_block;
        cur->_size = need_size;
    } else {
        pre->_next = cur->_next;
    }

    cur->_next = NULL;
    pool._size -= cur->_size;
    return cur->addr;
}

void pool_free(void* addr) {
    uint8_t* free_block_addr = addr - BLOCK_SIZE;
    block_t* cur = &pool._head;

    while (cur != pool._tail && (void*)cur->_next < addr) {
        assert(cur->_next != cur);
        cur = cur->_next;
    }

    if (cur == pool._tail) {
        return;
    }

    block_t* free_block = (block_t*)free_block_addr;
    pool._size += free_block->_size;

    free_block->_next = cur->_next;
    cur->_next = free_block;

    // merge free_block + next
    if (free_block_addr + free_block->_size == (uint8_t*)free_block->_next) {
        block_t* next = free_block->_next;
        if (next != pool._tail) {
            free_block->_size += next->_size;
            free_block->_next = next->_next;
        }
    }

    // merge cur + free_block
    if ((uint8_t*)cur + cur->_size == free_block_addr) {
        if (cur != &pool._head) {
            cur->_next = free_block->_next;
            cur->_size += free_block->_size;
        }
    }
}

void pool_print() {
    block_t* cur = &pool._head;

    while (cur != pool._tail) {
        printf("%p size = 0x%x, next = %p\n", cur, cur->_size, cur->_next);
        cur = cur->_next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    init_pool();

    uint32_t pool_size = pool._size;
    const uint32_t ORIGIN_SIZE = pool_size;
    void* addr = pool_malloc(pool_size + 1);
    assert(addr == NULL);

    int* p = (int*)pool_malloc(sizeof(int));
    *p = 0x12345678;
    assert(pool._size + align_int(sizeof(int) + BLOCK_SIZE) == ORIGIN_SIZE);
    assert(*p == 0x12345678);

    pool_size = pool._size;
    pool_free((void*)p);
    assert(pool._size - align_int(sizeof(int) + BLOCK_SIZE) == pool_size);
    assert(pool._size == ORIGIN_SIZE);
    // pool_print();

    int size = 1024;
    int count = pool._size / (size + BLOCK_SIZE);

    void* array[count];
    for (int i = 0; i < count; i++) {
        addr = pool_malloc(size);
        array[i] = addr;
        assert(addr != NULL);
        block_t* tmp = (block_t*)(addr - BLOCK_SIZE);
        assert(tmp->_size == (size + BLOCK_SIZE));

        memset(addr, 0x12, size);
    }
    assert(pool_malloc(1024) == NULL);

    for (int i = 0; i < count; i++) {
        // pool_print();
        pool_free(array[i]);
        // pool_print();
    }

    assert(pool._size == ORIGIN_SIZE);

    for (int i = 0; i < count; i++) {
        addr = pool_malloc(size);
        array[i] = addr;
        assert(addr != NULL);
        block_t* tmp = (block_t*)(addr - BLOCK_SIZE);
        assert(tmp->_size == (size + BLOCK_SIZE));
    }
    assert(pool_malloc(1024) == NULL);

    void* array1[1024];
    int array1_count = 0;
    size = 10;
    while (1) {
        addr = pool_malloc(size);
        if (size <= 0) {
            break;
        }
        if (addr != NULL) {
            array1[array1_count++] = addr;
        }
        else {
            size--;
        }
    }
    for (int i = 0; i < array1_count; i++) {
        pool_free(array1[i]);
    }

    for (int i = 0; i < count; i++) {
        pool_free(array[i]);
    }

    assert(pool._size == ORIGIN_SIZE);
    pool_print();

    return 0;
}