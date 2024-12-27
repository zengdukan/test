#include <future>
#include <thread>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <iomanip>  
#include <ctime>  

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


int f(int x, int y) {
    sleep(5);
    return x + y;
}

void test_lambda() {
    std::packaged_task<int(int, int)> task([](int a, int b) {
        sleep(5);
        return a + b;
    });
    future<int> result = task.get_future();

    str_now();
    task(10, 100);
    str_now();

    cout << "task lambda: " << result.get() << "\n";
    str_now();

}

void test_bind() {
    packaged_task<int()> task(bind(f, 1, 100));
    future<int> result = task.get_future();

    str_now();
    task();
    str_now();

    cout << "task lambda: " << result.get() << "\n";
    str_now();
}

void test_thread() {
    packaged_task<int(int, int)> task(f);
    future<int> result = task.get_future();

    thread task_td(std::move(task), 2, 10);

    
    str_now();
    cout << "task lambda: " << result.get() << "\n";
    str_now();

    task_td.join();
}

int main(int argc, char* argv[]) {
    // test_lambda();
    // test_bind();
    test_thread();


    return 0;
}