#define _GNU_SOURCE
#include <dlfcn.h>
#include <link.h>

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>

#define BT_SIZE 10

void* converToELF(void *addr) {
    Dl_info info;
    struct link_map *link;
    dladdr1(addr, &info, (void **)&link, RTLD_DL_LINKMAP);
    return (void *)((size_t)addr - link->l_addr);
}

void bt()
{
    int nptrs;
    void *buffer[BT_SIZE + 1] = {0};
    nptrs = backtrace(buffer, BT_SIZE);
    // printf("backtrace() returned %d addresses\n", nptrs);

    // for (size_t j = 0; j < nptrs; j++)
    //   printf("%p\n", converToELF(buffer[j]));
}

void func3(int argc)
{
    if (argc == 2)
        bt();
}

void func2(int argc)
{
    func3(argc);
}

void func1(int argc)
{
    func2(argc);
}

int main(int argc, char* argv[])
{
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    int i = 0;
    const int64_t run_time = 1000000;
    for (; i < run_time; i++)
        func1(argc);

    gettimeofday(&tv2, NULL);

    double ts1 = (double)tv1.tv_sec * 1000000 + tv1.tv_usec;
    double ts2 = (double)tv2.tv_sec * 1000000 + tv2.tv_usec;
    double used = (ts2 - ts1) / run_time;
    printf("%.2f\n", used);
    return 0;
}
