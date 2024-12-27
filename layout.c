#include <stdio.h>
#include <math.h>

void findKAndM(int n) {
    // 计算k的初始值，k是小于或等于sqrt(n)的最大整数
    int k = (int)sqrt(n);
    int m = k + 1; // m初始化为k+1

    // 如果k的平方小于n，那么m需要减小1
    if (k * k < n) {
        m = k;
    }

    // 输出k和m
    printf("%d -> %d * %d\n", n, k, m);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // 检查输入是否为正整数
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    findKAndM(n);
    return 0;
}