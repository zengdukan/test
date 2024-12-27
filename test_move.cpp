#include <iostream>
using namespace std;

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

Foo test() {
    Foo foo;
    return foo;
}

struct BaseA {
    int _a;
};

struct BaseB {
    int _a;
};

struct Derive: public BaseA, public BaseB {

};

int main(int argc, char* argv[]) {
    Foo&& f1 = Foo();
    Foo f2 = f1;

    Derive d;
    d.BaseA::_a = 10;
    d.BaseB::_a = 100;

    return 0;
}
