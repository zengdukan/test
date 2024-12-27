#include <stdio.h>

int _myAtoi(const char* s) {
        int ret = 0;
        int less_0 = 0;

        while ((*s == '0' || *s == ' ') && *s != '\0') {
            printf("[%s:%d] %d, %c\n", __FUNCTION__, __LINE__, ret, *s);
            s++;
        }

        if (*s == '-') {
            s++;
            less_0 = 1;
        } else if (*s == '+') {
            s++;
        } else if (*s < '0' || *s > '9') {
            printf("[%s:%d] %d, %c\n", __FUNCTION__, __LINE__, ret, *s);
            return 0;
        }
        
        while ((*s == '0' || *s == ' ') && *s != '\0') {
            printf("[%s:%d] %d, %c\n", __FUNCTION__, __LINE__, ret, *s);
            s++;
        }
        
        while (*s != '\0') {
            printf("[%s:%d] %d, %c\n", __FUNCTION__, __LINE__, ret, *s);
            if (*s < '0' || *s > '9') {
                printf("skip\n");
                break;
            }

            ret = ret * 10 + (*s - '0');
            s++;            
        }

        return less_0 ? -ret : ret;
    }

    int main(int argc, char* argv[]) {
        printf("%d\n", _myAtoi(argv[1]));

        return 0;
    }