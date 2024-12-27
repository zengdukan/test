#include <stdio.h>
#include <string.h>

void print(char* sz, int size, int idx, char* target, int* flag) {
    if (idx == size) {
        printf("%s\n", target);
        return;
    }
    int i = 0;
    for (; i < size; i++) {
        if (flag[i])
            continue;
        target[idx] = sz[i];
        flag[i] = 1;
        print(sz, size, idx + 1, target, flag);
        target[idx] = 0;
        flag[i] = 0;
    }
}

int main(int argc, char* argv[]) {
    char sz[] = "ab";
    char target[10] = {0};
    int flag[] = {0, 0, 0};
    memset(target, 0, sizeof(target));
    print(sz, strlen(sz), 0, target, flag);

    return 0;
}