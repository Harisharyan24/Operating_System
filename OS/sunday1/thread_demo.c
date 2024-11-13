#include<stdio.h>
#include<pthread.h>

void *cat()
{
    printf("MEOW\n");
}
void *mouse()
{
    printf(" KICHKICH\n");
}

int main()
{
    pthread_t id;
    pthread_t id1;
    pthread_create(&id,NULL,cat,NULL);
    pthread_create(&id1,NULL,mouse,NULL);
    pthread_create(&id1,NULL,mouse,NULL);
    pthread_join(id,NULL);
    pthread_join(id1,NULL);
    //pthread_join(id1,NULL);
    return 0;    
}