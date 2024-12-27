#include <stdio.h>

void __attribute__((constructor)) funcBeforeMain()
{
    printf("%s...\n", __FUNCTION__);
}

void __attribute__((destructor)) funcAfterMain()
{
    printf("%s...\n", __FUNCTION__);
}
