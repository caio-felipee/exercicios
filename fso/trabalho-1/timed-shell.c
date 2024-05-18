#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define MAX 256

int main()
{
    char *path = malloc(sizeof(char) * MAX), *arg = malloc(sizeof(char) * MAX);
    double total = 0.0;

    struct timeval gstart, gend;
    gettimeofday(&gstart, NULL);

    while(scanf(" %s %s", path, arg) == 2)
    {
        fflush(stdin);
        fflush(stdout);
        int pid = fork();

        struct timeval start, end;
        gettimeofday(&start, NULL);

        if(pid == 0)
        {
            int ret = execl(path, path, arg, NULL);

            char *error = strerror(errno);
            if(strcmp(error, "Success") != 0)
            {
                printf("> Erro: %s\n", error);
            }
            fflush(stdin);
            fflush(stdout);
            exit(errno);
        }

        int rn;
        wait(&rn);
        rn = WEXITSTATUS(rn);

        gettimeofday(&end, NULL);

        double time = (double)(end.tv_sec - start.tv_sec) + ((double)(end.tv_usec - start.tv_usec)/1000000.0);

        total += time;
        printf("> Demorou %.1lf segundos, retornou %d\n", time, rn);
    }

    gettimeofday(&gend, NULL);
    printf(">> O tempo total foi de %.1lf segundos\n", total);
}
