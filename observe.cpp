#include <algorithm>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <iostream>
using namespace std;

struct Observer {

    virtual ~Observer() {}
    virtual void update(int value) = 0;
    virtual std::string name() = 0;
};

struct ObserverImpl: public Observer {
    std::string _name;
    ObserverImpl(const std::string& name): _name(name) {

    }
    
    void update(int value) override {
        cout << _name << ":" << value << "\n";
    }

    std::string name() override {
        return _name;
    }
};

struct Observable
{
    int _value = 0;
    std::mutex _mutex;
    std::vector<std::weak_ptr<Observer>> _observers;

    void regObserver(const std::weak_ptr<Observer>& observer) {
        _observers.push_back(observer);
    }

    void unregObserver(const std::string& name) {
        _observers.erase(std::remove_if(_observers.begin(), _observers.end(), [name](const std::weak_ptr<Observer>& ob) {
            auto share_ob = ob.lock();
            if (share_ob) {
                return share_ob->name() == name;
            }
            return false;
        }));
    }

    void incr()
    {
        int current = 0;
        {
            std::lock_guard<std::mutex> lock(_mutex);
            _value++;
            current = _value;
        }
        update(current);
    }

    void update(int value)
    {
        cout << "observer size = " << _observers.size() <<"\n";
        for (auto observer: _observers) {
            auto share_ob = observer.lock();
            if (share_ob) {
                share_ob->update(value);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    Observable observable;
    {
        std::shared_ptr<Observer> ob1(new ObserverImpl("ob1"), [&](Observer* ob) {
            observable.unregObserver(ob->name());
            delete ob;
        });
        observable.regObserver(ob1);
        observable.incr();
    }
    observable.incr();
    
    return 0;
}