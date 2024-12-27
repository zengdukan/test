#include <atomic>
#include <ratio>
#include <vector>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std;

class LockFreeQueue {
public:
    atomic_int _lock = 0;
    void lock() {
        int n = 0;
        while (!_lock.compare_exchange_strong(n, 1, std::memory_order_acquire)) {
            this_thread::sleep_for(chrono::microseconds(1));
            n = 0;
        }
    }
    void unlock() {
        _lock.store(0, std::memory_order_release);
    }
};

int n = 0;
LockFreeQueue lock;
void calc() {
    for (int i = 0; i < 100000; i++) {
        lock.lock();
        ++n;
        lock.unlock();
    }
}

int main(int argc, char* argv[]) {
    vector<thread> thrds;
    for (int i = 0; i < 100; i++) {
        thrds.emplace_back(calc);
    }

    for (int i = 0; i < 100; i++) {
        thrds[i].join();
    }

    cout << n << "\n";
    return 0;
}