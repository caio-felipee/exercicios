#include <stdio.h>
#include <pthread.h>

struct thread_arg {
    int vezes;
};

int work(int id);

int count = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg)
{
    struct thread_arg *st = (struct thread_arg*)arg;

    for(int i = 0; i < st->vezes; i++)
    {
        pthread_mutex_lock(&mut);
        int id = ++count;
        pthread_mutex_unlock(&mut);
        work(id);
    }

    pthread_exit(NULL);
}
