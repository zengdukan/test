#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char buf[] = "0123456789";
    memcpy(&buf[2], buf, 5);
    printf("%s\n", buf);
    return 0;
}