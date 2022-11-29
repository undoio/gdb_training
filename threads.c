#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>


char spinners[] = "aaaa";

static void *
looper(void *p)
{
    int idx = (intptr_t) p;
    while (1)
    {
        spinners[idx]++;
        if (spinners[idx] > 'z') spinners[idx] = 'a';

        printf("%s\r", spinners);
        fflush(stdout);
        usleep(100000);
    }
}

int
main(void)
{
    int thread_count = 4;
    pthread_t threads[thread_count];
    for (intptr_t i = 0; i < thread_count; i++)
    {
        int e = pthread_create(&threads[0], NULL, looper, (void*)i);
        assert(!e);
    }

    for (int i = 0; i < thread_count; i++)
    {
        int e = pthread_join(threads[0], NULL);
        assert(!e);
    }

    return 0;
}
