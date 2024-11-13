#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define THREADS 3
void *functn(void* args)
{
     sleep(1);
    printf("FUNCTN THREAD EXECUTED\n");

}
int main()
{
    pthread_t id[THREADS];
    pthread_attr_t detachedThread;
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread,PTHREAD_CREATE_DETACHED);
    int i;
    for (i=0;i<THREADS;i++)
    {
    if(pthread_create(&id[i],&detachedThread,&functn,NULL)!=0)
    {
        perror("FAILED TO CREATE THE THREAD\n");
    }
    }
    // for(i=0;i<THREADS-1;i++)
    // {
    //     if(pthread_join(id[i],NULL)!=0)
    //     {
    //         perror("thread is unable to join\n");
    //     }
    // }
    pthread_attr_destroy(&detachedThread);
    pthread_exit(0);
}