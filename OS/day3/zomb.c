#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
    pid_t id;
    id=fork();
    id =fork();
    if(0==id)
    {
        printf("CHILD PID=%d ppid=%d\n",getpid(),getppid());
        exit(0);
    }
    else
    {
        sleep(10);
        printf("PARENT PID=%d ppid=%d\n",getpid(),getppid());

    }
    // while(1)
    // {
    //     id =fork();
    // if(0==id)
    // {
    //     printf("CHILD PID=%d ppid=%d\n",getpid(),getppid());
    //     exit(0);
    // }
    // else
    // {
    //     // sleep(1);
    //     printf("PARENT PID=%d ppid=%d\n",getpid(),getppid());

    // }
    }


