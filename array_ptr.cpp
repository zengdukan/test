#include <iostream>
using namespace std;

void print(int (&array)[3]) {
    cout << sizeof(array) << "\n";
}


int main(int argc, char* argv[]) {
    int array[] = {1, 2, 3};
    cout << sizeof(array) << "\n";
    print(array);

    return 0;
}