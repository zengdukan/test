#include <memory>
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {
    unique_ptr<int[]> a1(new int[5]{0, 1, 2, 3, 4});
    for (int i = 0; i < 5; i++) {
        cout << a1[i] << "\n";
    }

    shared_ptr<int> a2(new int[5]{0, 1, 2, 3, 4}, [](int* p) {
        delete []p;
    });
    for (int i = 0; i < 5; i++) {
        cout << a2.get()[i] << "\n";
    }
    return 0;
}