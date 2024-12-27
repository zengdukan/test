#include "template_split.h"

int main(int argc, char* argv[]) {
    Foo<int> foo;
    int n = 100;
    foo.print(n);

    return 0;
}