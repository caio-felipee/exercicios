#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int status = 0;

void handle(int signum)
{
    if(signum == SIGUSR1 || signum == SIGUSR2)
        ++status;
}

int main()
{
    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);

    pause();
    int x = fork();

    if(x == 0)
        exit(0);
    
    pause();
    wait(NULL);
    pause();
    exit(0);
}
