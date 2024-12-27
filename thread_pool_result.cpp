#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <future>
#include <functional>
#include <chrono>
#include <iomanip>  
#include <ctime>  

using namespace std;

template<typename T>
struct BlockQueue {

    void push(T&& t) {
        lock_guard<mutex> guard(_mutex);
        _q.push(t);
        _cond.notify_one();
    }

    void get(T& t) {
        unique_lock<mutex> guard(_mutex);
        while (_q.empty() && !_quit) {
            _cond.wait(guard);
        }

        if (_quit) {
            return;
        }

        t = _q.front();
        _q.pop();
    }

    void wake_up() {
        lock_guard<mutex> guard(_mutex);
        _quit = true;
        _cond.notify_all();
    }

    queue<T> _q;
    condition_variable _cond;
    mutex _mutex;
    bool _quit = false;
};


struct ThreadPool {
    using Task = function<void()>;

    ThreadPool(int task_size) {
        for (int i = 0; i < task_size; i++) {
            _threads.emplace_back(&ThreadPool::work, this);
        }
    }

    ~ThreadPool() {
        _quit = true;
        _q.wake_up();
        for (int i = 0; i < _threads.size(); i++) {
            _threads[i].join();
        }
    }

    template<typename F, typename... Args>
    auto add(F&& f, Args&&... args) {
        using result_type = typename std::result_of<F(Args...)>::type;
        shared_ptr<std::packaged_task<result_type()>> task(new std::packaged_task<result_type()>(std::bind(std::forward<F>(f), std::forward<Args>(args)...)));
        std::future<result_type> ret = task->get_future();

        _q.push([task]() {
            (*task)();
        });

        return ret;
    }

    void work() {
        Task t;
        while (true) {
            _q.get(t);
            if (_quit) {
                break;
            }

            t();
        }
    }


    BlockQueue<Task> _q;
    vector<thread> _threads;
    bool _quit = false;
};

void print() {
    cout << "print\n";
}

void print1(int n) {
    cout << n << "\n";
}

int sum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

using namespace std;


void str_now() {
    // 获取当前时间点  
    auto now = std::chrono::system_clock::now();  
      
    // 将时间点转换为 time_t 类型，表示自 Unix 纪元以来的秒数  
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);  
      
    // 将 time_t 类型转换为 tm 结构，表示本地时间  
    std::tm* now_tm = std::localtime(&now_time_t);  
      
    // 输出时间  
    std::cout << "当前时间: "  
              << (now_tm->tm_year + 1900) << "-"  // 年份  
              << std::setw(2) << std::setfill('0') << (now_tm->tm_mon + 1) << "-"  // 月份  
              << std::setw(2) << std::setfill('0') << now_tm->tm_mday << " "  // 日  
              << std::setw(2) << std::setfill('0') << now_tm->tm_hour << ":"  // 小时  
              << std::setw(2) << std::setfill('0') << now_tm->tm_min << ":"  // 分钟  
              << std::setw(2) << std::setfill('0') << now_tm->tm_sec  // 秒  
              << std::endl;  
}

int main(int argc, char* argv[]) {
    str_now();
    ThreadPool pool(10);

    auto r1 = pool.add(std::bind(sum, 1, 2));
    auto r2 = pool.add(std::bind(sum, 100, 200));
    auto r3 = pool.add(print);
    auto r4 = pool.add(print1, 1000);

    str_now();
    // 获取异步任务的结果  
    try {  
        std::cout << "Result: " << r1.get() << ", " << r2.get() << std::endl;  
    } catch (const std::exception &e) {  
        std::cerr << "Exception: " << e.what() << std::endl;  
    }  
    
    str_now();
    return 0;
}