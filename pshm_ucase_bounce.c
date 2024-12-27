#include <pthread.h>
#include <unistd.h>

#include "pshm_ucase.h"

int main(int argc, char *argv[])
{
    int fd;
    char *shmpath;
    struct shmbuf *shmp;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s /shm-path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    shmpath = argv[1];

    /* Create shared memory object and set its size to the size
       of our structure. */

    fd = shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR, 0600);
    if (fd == -1)
        errExit("shm_open");

    if (ftruncate(fd, sizeof(struct shmbuf)) == -1)
        errExit("ftruncate");

    /* Map the object into the caller's address space. */

    shmp = mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shmp == MAP_FAILED)
        errExit("mmap");

    /* Initialize semaphores as process-shared, with value 0. */
    pthread_mutexattr_t ma;
    pthread_mutexattr_init(&ma);
    pthread_mutexattr_setpshared(&ma, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&shmp->_mutex, &ma);

    pthread_condattr_t ca;
    pthread_condattr_init(&ca);
    pthread_condattr_setpshared(&ca, PTHREAD_PROCESS_SHARED);
    pthread_cond_init(&shmp->_cond, &ca);
    shmp->_n = 0;

    /* Wait for 'sem1' to be posted by peer before touching
       shared memory. */
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&shmp->_mutex);
        shmp->_n++;
        if (shmp->_n > 5)
            pthread_cond_broadcast(&shmp->_cond);
        printf("%d\n", shmp->_n);
        pthread_mutex_unlock(&shmp->_mutex);
        sleep(1);
    }

    /* Unlink the shared memory object. Even if the peer process
       is still using the object, this is okay. The object will
       be removed only after all open references are closed. */

    shm_unlink(shmpath);

    exit(EXIT_SUCCESS);
}
