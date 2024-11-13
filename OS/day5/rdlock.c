#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<err.h>
pthread_rwlock_t rwlock;

void err_check(int err, const char *msg) {
    if (err != 0) {
        perror(msg);
        exit(1);
    }
}

void *read_1()
{
    while(1)
    {
    pthread_rwlock_rdlock(&rwlock);
    printf("read_1: locked\n");
    sleep(1);
    pthread_rwlock_unlock(&rwlock);
    printf("read_1: unlocked\n");
    sleep(2);
    }
}

void *read_2()
{
    while(1)
    {
    pthread_rwlock_rdlock(&rwlock);
    printf("read_2: locked\n");
    sleep(1);
    pthread_rwlock_unlock(&rwlock);
    printf("read_2: unlocked\n");
    sleep(2);
    }
}

void *write_1(void *data)
{
    while(1)
    {
     {
    pthread_rwlock_wrlock(&rwlock);
    printf("write_1: locked\n");
    sleep(1);
    pthread_rwlock_unlock(&rwlock);
    printf("write_1: unlocked\n");
    sleep(2);
    }   
    }
}

void *write_2(void *data)
{
    while(1)
    {
     {
    pthread_rwlock_wrlock(&rwlock);
    printf("write_2: locked\n");
    sleep(1);
    pthread_rwlock_unlock(&rwlock);
    printf("write_2: unlocked\n");
    sleep(2);
    }   
    }
}

int main()
{
    pthread_t rd1,rd2,wr1,wr2;
    int err;
    pthread_rwlock_init(&rwlock,NULL);

    err=pthread_create(&rd1,NULL,read_1,NULL);
    err_check(err,"Creating thread: read1\n");

    err=pthread_create(&rd2,NULL,read_2,NULL);
    err_check(err,"Creating thread: read2\n");

    err=pthread_create(&wr1,NULL,write_1,NULL);
    err_check(err,"Creating thread: write1\n");

    err=pthread_create(&wr2,NULL,write_2,NULL);
    err_check(err,"Creating thread: write2\n");

    err=pthread_join(rd1,NULL);
    err_check(err,"Joining thread:read1\n");

    err=pthread_join(rd2,NULL);
    err_check(err,"Joining thread:read2\n");

    err=pthread_join(wr1,NULL);
    err_check(err,"Joining thread:write1\n");

    err=pthread_join(wr2,NULL);
    err_check(err,"Joining thread:write2\n");

    pthread_rwlock_destroy(&rwlock);
}