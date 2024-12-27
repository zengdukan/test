#include <string.h>

#include "pshm_ucase.h"

int main(int argc, char *argv[])
{
    int fd;
    char *shmpath, *string;
    size_t len;
    struct shmbuf *shmp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s /shm-path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    shmpath = argv[1];

    /* Open the existing shared memory object and map it
       into the caller's address space. */

    fd = shm_open(shmpath, O_RDWR, 0);
    if (fd == -1)
        errExit("shm_open");

    shmp = mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shmp == MAP_FAILED)
        errExit("mmap");

    /* Copy data into the shared memory object. */

    /* Tell peer that it can now access shared memory. */
#if 1
    pthread_mutex_lock(&shmp->_mutex);
    while (shmp->_n <= 5) {
        pthread_cond_wait(&shmp->_cond, &shmp->_mutex);
    }
    printf("%d\n", shmp->_n);
    pthread_mutex_unlock(&shmp->_mutex);
#else
    int i = 0;
    for (; i < 5; i++)
    {
        printf("%d\n", shmp->_n);
        sleep(1);
    }
#endif

    /* Write modified data in shared memory to standard output. */

    exit(EXIT_SUCCESS);
}
