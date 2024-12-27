#define _GNU_SOURCE
#include <dlfcn.h>
#include <link.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>

#define BT_SIZE 10

void* converToELF(void *addr) {
    Dl_info info;
    struct link_map *link;
    dladdr1(addr, &info, (void **)&link, RTLD_DL_LINKMAP);
    return (void *)((size_t)addr - link->l_addr);
}

void bt()
{
    void* arr[BT_SIZE] = {0};
    int iIndex = 0;
	void *pFrame;
	// NOTE: we can't use "for" loop, __builtin_* functions
	// require the number to be known at compile time
    do {
        arr[iIndex++] = (                  (pFrame = __builtin_frame_address(0)) != NULL) ? __builtin_return_address(0) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(1)) != NULL) ? __builtin_return_address(1) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(2)) != NULL) ? __builtin_return_address(2) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(3)) != NULL) ? __builtin_return_address(3) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(4)) != NULL) ? __builtin_return_address(4) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(5)) != NULL) ? __builtin_return_address(5) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(6)) != NULL) ? __builtin_return_address(6) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(7)) != NULL) ? __builtin_return_address(7) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(8)) != NULL) ? __builtin_return_address(8) : NULL; if (iIndex == BT_SIZE || pFrame == NULL) break;
        arr[iIndex++] = (pFrame != NULL && (pFrame = __builtin_frame_address(9)) != NULL) ? __builtin_return_address(9) : NULL;
    } while (0);

	// fill remaining spaces
	// for (; iIndex < BT_SIZE; iIndex++)
	// 	arr[iIndex] = NULL;

    // int i = 0;
    // for (i = 0; i < iIndex && arr[i] != NULL; i++)
    // {
    //     printf("%p\n", converToELF(arr[i]));
    // }
}

void func3(int argc)
{
    if (argc == 2)
        bt();
}

void func2(int argc)
{
    func3(argc);
}

void func1(int argc)
{
    func2(argc);
}

int main(int argc, char* argv[])
{
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    int i = 0;
    const int64_t run_time = 100000000;
    for (; i < run_time; i++)
        func1(argc);

    gettimeofday(&tv2, NULL);

    double ts1 = (double)tv1.tv_sec * 1000000 + tv1.tv_usec;
    double ts2 = (double)tv2.tv_sec * 1000000 + tv2.tv_usec;
    double used = (ts2 - ts1) / run_time;
    printf("%.2f\n", used);
    return 0;
}
