#include <iostream>
#include <type_traits>
#include <utility>

using namespace std;

template<typename Ret, typename... Args>
struct Func;

template<typename Ret, typename... Args>
struct Func<Ret(Args...)> {
    struct Base {
        virtual Ret operator()(Args&&... args) = 0;
    };
    template<typename T>
    struct Data: Base {
        T data;
        Data(const T& t): data(t) {}
        Ret operator()(Args&&... args) {
            return data(std::forward<Args>(args)...);
        }
    };

    Base* ptr;
    Func(): ptr(nullptr) {}

    template<typename T>
    Func(T t): ptr{new Data<T>(t) } {

    }

    Ret operator()(Args... args) {
         return (*ptr)(std::forward<Args>(args)...);
    }
};

void print(int n) {
    cout << n << "\n";
}




int main(int argc, char* argv[]) {
    Func<void(int)> func = print;
    func(10);
    
    return 0;
}

