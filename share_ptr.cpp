#include <cstddef>
#include <iostream>
#include <assert.h>
#include <atomic>

using namespace std;

template<typename T>
class MySharedPtr {
public:
    MySharedPtr(T* t): _t(t) {
        _control_block = new ControlBlock;
        _control_block->_count++;
    }

    ~MySharedPtr() {
        _control_block->_count--;
        if (_control_block->_count == 0) {
            delete _t;
            delete _control_block;
        }
    }

    MySharedPtr(const MySharedPtr& other) {
        _t = other._t;
        _control_block = other._control_block;
        _control_block->_count++;
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this == &other) {
            return *this;
        }

        if (_t) {
            _control_block->_count--;
            if (_control_block->_count == 0) {
                delete _t;
                delete _control_block;
            }
        }

        _t = other._t;
        _control_block = other._control_block;
        _control_block->_count++;

        return *this;
    }

    T& operator*() {
        return *_t;
    }

    T* operator->() {
        return _t;
    }

    struct ControlBlock {
        atomic_int _count{0};
    };
    ControlBlock* _control_block{nullptr};
    T* _t{nullptr};
};

class RefCount {
public:
    RefCount() {

    }

    virtual ~RefCount() {

    }

    void addRef() {
        _count++;
    }

    bool delRef() {
        _count--;
        if (_count == 0) {
            delete this;

            return true;
        }

        return false;
    }

    atomic_int _count{0};
};

template<typename T>
class IntrusiveSharePtr {
public:
    IntrusiveSharePtr(T* t): _t(t) {
        _t->addRef();
    }

    ~IntrusiveSharePtr() {
        if (_t && _t->delRef()) {
            _t = nullptr;
        }
    }

    IntrusiveSharePtr(const IntrusiveSharePtr& other) {
        _t = other._t;
        _t->addRef();
    }

    IntrusiveSharePtr& operator=(const IntrusiveSharePtr& other) {
        if (this != &other) {
            if (_t && _t->delRef()) {
                _t = nullptr;
            }

            _t = other._t;
            _t->addRef();
        }

        return *this;
    }

    T* operator->() {
        return _t;
    }

    T& operator*() {
        return *_t;
    }

    T* _t{nullptr};
};

void test_my_shared_ptr() {
    MySharedPtr<int> p1(new int(10));
    MySharedPtr<int> p2 = p1;

    assert(*p1 == 10);
    assert(*p2 == 10);

    MySharedPtr<int> a1(new int(100));
    assert(*a1 == 100);
    a1 = p1;
    assert(*a1 == 10);
}

struct Foo: public RefCount {
    int _a;

    Foo(int a): _a(a) {

    }
};

void test_intrusive_ptr() {
    IntrusiveSharePtr<Foo> a1(new Foo(10));
    IntrusiveSharePtr<Foo> a2 = a1;

    assert(a1->_a == 10);
    assert(a2->_a == 10);

    IntrusiveSharePtr<Foo> f1(new Foo(100));
    assert(f1->_a == 100);
    
    a2 = f1;
    assert(a2->_a == 100);
}

int main(int argc, char* argv[]) {
    test_my_shared_ptr();
    test_intrusive_ptr();

    return 0;
}