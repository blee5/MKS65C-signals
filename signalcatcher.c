#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sighandler(int signum)
{
    if (signum == SIGINT)
    {
        printf("Exiting due to SIGINT.\n");
        exit(0);
    }
    else if (signum == SIGUSR1)
    {
        printf("SIGUSR1 caught.\nParent PID is %d\n", getppid());
    }
}

int main()
{
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    for(;;)
    {
        sleep(1);
        printf("Hello! My PID is %d\n", getpid());
    }
}

