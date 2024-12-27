#include <iostream>
using namespace std;

class Base {
public:
    int _a;

    void f1() {

    }

    virtual void f2() {
        cout << "f2\n";
    }

    virtual void f3() {
        cout << "f3\n";
    }

    virtual void f4() {
        cout << "f4\n";
    }
};

struct Base2 {
    virtual void p1() {

    }

    int _b;
};

class Derive: public Base, public Base2 {
public:
    virtual void f2() {
        cout << "Derive f2\n";
    }
};

typedef void (*f)();

struct vptr_t {
    f _ptr[0];
};

int main(int argc, char* argv[]) {
    Base base, base2;
    
    // long* vptr = (long*)&base;
    // f f2 = (f)(*(long*)*vptr);
    // f2();

    // f f3 = (f)(*((long*)*vptr + 1));
    // f3();

    vptr_t* vptr = (vptr_t*)(*(long*)&base);
    vptr->_ptr[0]();
    vptr->_ptr[1]();
    vptr->_ptr[2]();

    vptr_t* vptr2 = (vptr_t*)(*(long*)&base2);
    printf("%p, %p\n", vptr->_ptr, vptr2->_ptr);

    Derive d;
    Base2* br = &d;
    printf("%p, %p, %d, %d, %d\n", &d, br, sizeof(d), sizeof(Base), sizeof(Base2));
    br->p1();

    return 0;
}