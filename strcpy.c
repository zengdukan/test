#include <stdio.h>

char* _strcpy(const char* src, char* dst) {
    if (src == NULL || dst == NULL)
        return dst;

    char* tmp = dst;
    while (*src != 0) {
        *dst++ = *src++;
    }

    return tmp;
}

void endin() {
    union {
        char _c;
        int _i;
    } u;
    u._i = 1;
    if (u._c == 1) {
        // small
    } else {
        // bit
    }
}

int main(int argc, char* argv[]) {

}