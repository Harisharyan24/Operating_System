#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void main()
{
        pid_t id=fork();
    //printf("---SHELL---");
    if(0==id)
    {
        printf("child: pid\n");
    execl("/usr/bin/ls","ls","-al",NULL);
    }
    else
    {
        printf("parent: pid\n");
          // wait(10);
        execl("/usr/bin/cat","cat","exec_1.c",NULL);
     
    }
}