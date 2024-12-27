#include <stdio.h>

class A {
public:
    virtual void print()
    {

    }

    int _test;
};


int main(int argc, char* argv[]) {
    A* a1 = new A;
    A* a2 = new A;
    return 0;
}