#include <stdio.h>


int main(int argc, char* argv[])
{
    int n1 = 10;
    int n2 = 20;
    int* const p1 = &n1;
    *p1 = n2;
}