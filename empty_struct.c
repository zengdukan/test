#include <stdio.h>

struct EmptyStruct {

};

int main(int argc, char* argv[]) {

    struct EmptyStruct arr[10];
    printf("%d, %d\n", sizeof(struct EmptyStruct), sizeof(arr));

    return 0;
}