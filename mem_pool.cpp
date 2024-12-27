#include <iostream>  
#include <vector>  
#include <new> // for std::bad_alloc  
#include <mutex>

class MemoryPool {  
public:  
    MemoryPool(size_t blockSize, size_t numBlocks)  
        : blockSize_(blockSize), numBlocks_(numBlocks), freeList_(numBlocks), pool_(blockSize * numBlocks) {  
        // Initialize the free list  
        for (size_t i = 0; i < numBlocks_; ++i) {  
            freeList_[i] = i;  
        }  
    }  
  
    ~MemoryPool() {  
        // Memory pool destructor, does nothing special in this simple implementation  
    }  
  
    void* allocate() {  
        std::lock_guard<std::mutex> lock(mutex_); // Uncomment if thread-safe is needed  
  
        if (freeList_.empty()) {  
            throw std::bad_alloc(); // No free blocks available  
        }  
  
        size_t index = freeList_.back();  
        freeList_.pop_back();  
  
        return pool_.data() + index * blockSize_;  
    }  
  
    void deallocate(void* ptr) {  
        std::lock_guard<std::mutex> lock(mutex_); // Uncomment if thread-safe is needed  
  
        if (ptr == nullptr) {  
            return;  
        }  
  
        size_t index = static_cast<char*>(ptr) - static_cast<char*>(pool_.data()) / blockSize_;  
  
        // Add the index back to the free list  
        freeList_.push_back(index);  
    }  
  
private:  
    size_t blockSize_;  
    size_t numBlocks_;  
    std::vector<size_t> freeList_;  
    std::vector<char> pool_;  
    // std::mutex mutex_; // Uncomment if thread-safe is needed  
};  
  
int main() {  
    try {  
        MemoryPool pool(1024, 10); // Create a pool with 10 blocks of 1024 bytes each  
  
        void* p1 = pool.allocate();  
        void* p2 = pool.allocate();  
  
        // Use allocated memory...  
  
        pool.deallocate(p1);  
        pool.deallocate(p2);  
  
        // Allocate again to demonstrate reuse  
        void* p3 = pool.allocate();  
  
    } catch (const std::bad_alloc& e) {  
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;  
    }  
  
    return 0;  
}