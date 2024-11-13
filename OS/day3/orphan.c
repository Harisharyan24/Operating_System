#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
    pid_t id;
    //printf("PARENT PID=%d ppid=%d\n",getpid(),getppid());
    //printf("CHILD PID=%d ppid=%d\n",getpid(),getppid());
    //printf("After>>>>>>>>>>>\n");
    id=fork();
    if(0==id)
    {
        printf("CHILD PID=%d ppid=%d\n",getpid(),getppid());
        sleep(10);
        printf("CHILD PID=%d ppid=%d\n",getpid(),getppid());
    }
    else
    {
        printf("PARENT PID=%d ppid=%d\n",getpid(),getppid());
    }
}

