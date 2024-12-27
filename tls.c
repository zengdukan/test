#include <stdio.h>
__thread int tls_n = 21;

int main(int argc, char* argv[]) {
    printf("%d\n", tls_n);

    return 0;
}