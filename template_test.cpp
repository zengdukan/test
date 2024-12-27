#include <memory>
#include <iostream>
using namespace std;

void print() {
    cout << "\n";
}

template<typename T>
void print(const T& t) {
    cout << t << "\n";
}

template<typename First, typename ...Rest>
void print(const First& first, const Rest& ...rest) {
    cout << first << ",";
    print(rest...);
}

template<typename T>
unique_ptr<T> to_move(unique_ptr<T> ptr) {
    cout << (ptr == nullptr) << "\n";
    return ptr;
}

struct Foo {
    Foo() {
        cout << "foo\n";
    }

    ~Foo() {
        cout << "~foo\n";
    }

    Foo(const Foo& foo) {
        cout << "copy\n";
    }

    Foo(const Foo&& foo) {
        cout << "move copy\n";
    }

    Foo& operator=(const Foo& foo) {
        cout << "=\n";
        return *this;
    }

    Foo& operator=(const Foo&& foo) {
        cout << "move =\n";
        return *this;
    }
};

template<typename T, int N>
struct MyArray {
    T _array[N];
    void print() {
        for (int i = 0; i < N; i++) {
            
        }
    }
};

template<typename T, typename N>
struct Boo {
    T _t;
    N _n;
};

template<typename T>
struct Boo<T, int>
{
    T _t;
    int _n;
};

template<>
struct Boo<int, int> {
    int _t;
    int _n;
};

int main(int argc, char* argv[]) {
    print(1,2, "abc", 12.34);

    unique_ptr<Foo> foo(new Foo);
    unique_ptr<Foo> foo1 = to_move(std::move(foo));

    MyArray<int, 10> myarray;
    return 0;
}