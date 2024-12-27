
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

struct CountDown {
    int _v;
    std::mutex _mutex;
    std::condition_variable _cond;

    explicit CountDown(int v): _v(v) {

    }

    void wait() {
        std::unique_lock<std::mutex> lock(_mutex);
        while (_v > 0) {
            _cond.wait(lock);
        }
    }

    void countDown() {
        std::lock_guard<std::mutex> lock(_mutex);
        _v--;
        if (_v == 0) {
            _cond.notify_all();
        }
    }

    int value() {
        return _v;
    }
}; 

void consume(CountDown& countDown, const std::string& name) {
    std::cout << name << " wait...\n";
    countDown.wait();
    std::cout << name << " 0\n";
}

int main(int argc, char* argv[]) {
    CountDown countDown(3);
    std::thread tr1(&consume, std::ref(countDown), "tr1");
    std::thread tr2(&consume, std::ref(countDown), "tr2");
    std::thread tr3(&consume, std::ref(countDown), "tr3");

    int v = 0;
    while ((v = getchar())) {
        countDown.countDown();

        std::cout << countDown.value() << "\n";
        if (countDown.value() == 0)
            break;
    }

    
    tr1.join();
    tr2.join();
    tr3.join();

    return 0;
}
