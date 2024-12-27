#include <memory>
#include <iostream>
#include <atomic>

using namespace std;



template<typename T>
class my_enable_shared_from_this {
public:
    my_enable_shared_from_this() {

    }

    shared_ptr<T> shared_from_this() {
        return shared_ptr<T>(_weak_ptr);
    }

    weak_ptr<T> _weak_ptr;
};

class Bad: public enable_shared_from_this<Bad> {
public:
    ~Bad() {
        cout << __FUNCTION__ << ":" << __LINE__ << "\n";
    }

    shared_ptr<Bad> get_shard_ptr() {
        return shared_from_this();
    }
};

template<typename T>
class MySharedPtr {
public:
    struct ControlClock {
        atomic_int _count{0};
    };
    T* _ptr;
    ControlClock* _cb;

    MySharedPtr(T* t) {
        _cb = new ControlClock;
        _cb->_count++;
        _ptr = t;
    }

    ~MySharedPtr() {
        _cb->_count--;
        if (_cb->_count == 0) {
            delete _ptr;
            delete _cb;
        }
    }

    MySharedPtr(const MySharedPtr& other) {
        other._cb->_count++;
        _cb =  other._cb;
        _ptr = other._ptr;
    }
    
};

class RefCount {
public:
    atomic_int _count{0};

    RefCount() {}

    virtual ~RefCount() {
        
    }


    void addRef() {
        _count++;
    }

    bool releaseRef() {
        if (--_count == 0) {
            delete this;
            return true;
        }

        return false;
    }

    RefCount(const RefCount& other) = delete;
    RefCount& operator=(const RefCount&) = delete;
};

template<typename T>
class IntrusivePtr {
public:
    T* _t;

    IntrusivePtr(T* t = nullptr): _t(t) {
        if (t) {
            t->addRef();
        }
    }

    IntrusivePtr(const IntrusivePtr& other) {
        _t = other._t;
        _t->addRef();
    }

    ~IntrusivePtr() {
        if (_t && _t->releaseRef()) {
            _t = nullptr;
        }
    }

    IntrusivePtr& operator=(const IntrusivePtr& other) {
        if (this != &other) {
            if (_t && _t->releaseRef()) {
                _t = nullptr;
            }

            _t = other._t;
            _t->addRef();
        }
    }
};

class IntrusiveBad: public RefCount {
public:
    IntrusiveBad() {
        cout << "IntrusiveBad\n";
    }

    ~IntrusiveBad() {
        cout << "~IntrusiveBad\n";
    }
};

int main(int argc, char* argv[]) {
    // shared_ptr<Bad> bad = make_shared<Bad>();
    // auto bad_ptr = bad->get_shard_ptr();

    // MySharedPtr<Bad> mybad(new Bad);
    // MySharedPtr<Bad> b2 = mybad;
    // MySharedPtr<Bad> b3 = mybad;

    IntrusivePtr<IntrusiveBad> ibad(new IntrusiveBad());
    IntrusivePtr<IntrusiveBad> ibad2 = ibad;
    IntrusivePtr<IntrusiveBad> ibad3 = ibad2;

    return 0;
}
