#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>
#include<stdlib.h>
void *exec_1()
{
   execl("/usr/bin/ls","ls","-al",NULL);
   exit(0);
}
void *exec_2()
{
    execl("/usr/bin/cat","cat","exec_1.c",NULL);
 printf("\n");
}
int main()
{
    pthread_t id1,id2;
    pthread_create(&id2,NULL,exec_2,NULL);
    pthread_create(&id1,NULL,exec_1,NULL);
    pthread_join(id2,NULL);
    pthread_join(id1,NULL);
    return 0;
}