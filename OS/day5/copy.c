#include<stdio.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define BUFF_SIZE 64
pthread_mutex_t mut;
int filesrc,filedest,in,out;
char buf[BUFF_SIZE];

void *readthread(void *data)
{ 
        pthread_mutex_lock(&mut);
        in = read(filesrc, buf, BUFF_SIZE);
        pthread_mutex_unlock(&mut);   
}

void *writethread(void *data)
{
    pthread_mutex_lock(&mut);
    while ((in = read(filesrc,buf,BUFF_SIZE))>= 0) 
    {   
        out = write(filedest,buf,in);
        if(-1 ==in|| 0==in)
            break;
    }
    pthread_mutex_unlock(&mut);
    
}

int main()
{
    filesrc=open("src.txt",O_RDWR | O_CREAT,S_IRWXU|S_IRGRP|S_IROTH);//opened src.txt file
  
    filedest=open("dest.txt",O_RDWR | O_CREAT,S_IRWXU|S_IRGRP|S_IROTH);//opened dest.txt file
    
    pthread_t re,wri;

    pthread_create(&re,NULL,readthread,NULL);
    pthread_create(&wri,NULL,writethread,NULL);
    pthread_mutex_init(&mut,NULL);

    pthread_join(re,NULL);
    //(buf);
    pthread_join(wri,NULL);
    //sleep(1);
    pthread_mutex_destroy(&mut);
    pthread_exit(0);
    close(filesrc);
    close(filedest);
    
}

