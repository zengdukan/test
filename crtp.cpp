#include <iostream>
using namespace std;

template<typename T>
class Base {
public:
    void f() {
        T* t = static_cast<T*>(this);
        t->f();
    }    
};

class D1 : public Base<D1> {
public:
    void f() {
        cout << "d1\n";
    }
};

class D2 : public Base<D2> {
public:
    void f() {
        cout << "d2\n";
    }
};

template<typename T>
void call_f(Base<T>* base) {
    base->f();
}

struct CA {
    CA() {
        cout << "ca\n";
    }

    ~CA() {
        cout << "~ca\n";
    }
};

struct CC {
    CC() {
        cout << "cC\n";
    }

    ~CC() {
        cout << "~cC\n";
    }
};

struct CB: public CA {
    CB() {
        cout << "cb\n";
    }

    ~CB() {
        cout << "~cb\n";
    }
    CC _cc;
};

void test() {
    static CC _cc;
}
CA ca;

int main(int argc, char* argv[]) {
    printf("MAIN\n");
    D1 d1;
    D2 d2;
    
    call_f(&d1);
    call_f(&d2);
    
    test();

    return 0;
}