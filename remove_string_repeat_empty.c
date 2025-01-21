#include <stdio.h>
#include <string.h>
void reomve_string_repeat_empty(char* str, int len)
{
    int slow = 0;
    int i = 0;
    int flag = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == ' ') {
            if (!flag) {
                flag = 1;
                str[slow++] = str[i];
            }
        }
        else {
            flag = 0;
            str[slow++] = str[i];
        }
    }

    str[slow] = '\0';
}

int main(int argc, char* argv[])
{
    char str[] = "  hello    world   man";
    reomve_string_repeat_empty(str, strlen(str));
    printf("%s\n", str);
    return 0;
}