#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t id;
    id=fork();
    if(0==id)
    {
        printf("Child process created\n");
        printf("PID IS %d, PPID IS %d\n",getpid(),getppid());
        sleep(10);
    }
    else
    {
        printf("parent process created\n");
        printf("PID IS %d, PPID IS %d\n",getpid(),getppid());
        wait(10);
    }
    return 0;
    
}