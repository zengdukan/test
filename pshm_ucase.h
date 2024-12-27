#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

#define errExit(msg)                                                                                                                                                                                   \
    do                                                                                                                                                                                                 \
    {                                                                                                                                                                                                  \
        perror(msg);                                                                                                                                                                                   \
        exit(EXIT_FAILURE);                                                                                                                                                                            \
    } while (0)

#define BUF_SIZE 1024 /* Maximum size for exchanged string */

/* Define a structure that will be imposed on the shared
   memory object */

struct shmbuf
{
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
    int _n;
    size_t cnt;         /* Number of bytes used in 'buf' */
    char buf[BUF_SIZE]; /* Data being transferred */
};
