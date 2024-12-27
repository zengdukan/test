#ifndef _FOO_IMPL_H_
#define _FOO_IMPL_H_

#include "foo.h"
#include <iostream>
using namespace std;
template<typename T>
void Foo<T>::f1(const T& n) {
    cout << n << "\n";
}

template<typename T>
void goo(T x) {
    cout << x << "\n";
}

#endif