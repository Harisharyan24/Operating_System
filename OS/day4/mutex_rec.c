#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t countMutex;
pthread_mutexattr_t rec;
int count=0;
void *inc()
{
    while(1)
    {
        pthread_mutex_lock(&countMutex);
         pthread_mutex_lock(&countMutex);
        count++;
        printf("INC: count=%d \n",count);
        pthread_mutex_unlock(&countMutex);
        pthread_mutex_unlock(&countMutex);
    }
}
void *dec()
{
    while(1)
    {
        pthread_mutex_lock(&countMutex);
        pthread_mutex_lock(&countMutex);
        count--;
        printf("DEC: count=%d \n",count);
        pthread_mutex_unlock(&countMutex);
        pthread_mutex_unlock(&countMutex);
    }
}
int main()
{
    pthread_t incID,decID;
    pthread_create(&incID,NULL,inc,NULL);
    pthread_create(&decID,NULL,dec,NULL);
    
    pthread_mutexattr_init(&rec);
    pthread_mutexattr_settype(&rec,PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&countMutex,&rec);

    pthread_join(decID,NULL);
    pthread_join(incID,NULL);

    pthread_mutex_destroy(&countMutex);
    pthread_mutexattr_destroy(&rec);
    return 0;
}