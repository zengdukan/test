#include <iostream>
using namespace std;

struct Data {
    int a;
    int b;

    ~Data() {
        cout << "~data\n";
    }
};

int main(int argc, char* argv[]) {
    char* buf = new char[100];
    Data* p = new(buf) Data;
    p->a = 10;
    cout << p->a << "\n";

    p->~Data();
    delete[] buf;

    return 0;
}