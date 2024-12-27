#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (*print_f)(int n);

typedef struct base_t {
    int _a;
    print_f _print;

    char priv[0];
} base_t;

void print(base_t* base, int n) {
    base->_print(n);
}

typedef struct derive_t {
    int _b;
} derive_t;


void print_a(int n) {
    printf("a: %d\n", n);
}

base_t* create_base_a() {
    base_t* base = (base_t*)calloc(1, sizeof(base_t));
    base->_print = print_a;

    return base;
}

void print_b(int n) {
    printf("b: %d\n", n);
}

base_t* create_derive() {
    base_t* base = (base_t*)calloc(1, sizeof(base_t) + sizeof(derive_t));
    derive_t* derive = (derive_t*)base->priv;
    base->_print = print_b;

    return base;
}

int main(int argc, char* argv[]) {
    base_t* base = create_base_a();
    base->_print(10);

    base = create_base_b();
    base->_print(20);

    return 0;
}