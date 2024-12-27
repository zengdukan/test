#include "template_split.h"

#include <iostream>
using namespace std;

template<typename T>
void Foo<T>::print(T& t) {
    cout << t << "\n";
}

template class Foo<int>;