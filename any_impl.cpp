#include <iostream>
#include <string>
using namespace std;

struct Any {
    template<typename T>
    Any(const T& t): ptr{new Data<T>(t)} {}

    template<typename T>
    T& get_data() {
        Data<T>* data = (Data<T>*)ptr;
        return data->data;
    }

    struct Base {

    };
    template<typename T>
    struct Data: Base {
        T data;
        Data(const T& t): data(t) {}
    };
    Base* ptr;
};

int main(int argc, char* argv[]) {
    Any a = 10;
    Any b = string("123");

    cout << a.get_data<int>() << ", " << b.get_data<string>() << "\n";
}