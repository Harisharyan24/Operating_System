#include<stdio.h>
#include<pthread.h>
void *dino()
{
    printf("Executing the dino function using thread 1\n");
}
void *ape()
{
    printf("Executing the ape function using the thread 2\n");
}
int main()
{
    pthread_t id1,id2;
    pthread_attr_t rhino;
    pthread_attr_init(&rhino);
    pthread_attr_setdetachstate(&rhino,PTHREAD_CREATE_DETACHED);
    pthread_create(&id1,&rhino,dino,NULL);
    pthread_create(&id2,NULL,ape,NULL);
    pthread_attr_destroy(&rhino);
    pthread_join(id2,NULL);
    printf("%d\n",pthread_self());
    pthread_exit(0);
    printf("MAIN thread has been terminated\n");
    return 0;
}