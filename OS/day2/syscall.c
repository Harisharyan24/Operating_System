#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <unistd.h>
#define BUF_SIZE 64
int main(int argc,char *argv[])
{
    int fd_s,fd_d,in,out;
    char buf[BUF_SIZE];
    fd_s =open("src.txt",O_RDWR | O_CREAT,S_IRWXU|S_IRGRP|S_IROTH);
    if(fd_s ==-1)
    {
        perror("Error while opening the src file\n");
        exit(EXIT_FAILURE);
    }
    fd_d =open("dest.txt",O_RDWR | O_CREAT,S_IRWXU|S_IRGRP|S_IROTH);
    if(fd_d ==-1)
    {
        perror("Error while opening the dest file\n");
        exit(EXIT_FAILURE);
    }
  
    while (  (in = read(fd_s, buf, BUF_SIZE))> 0) 
    {
        out = write(fd_d, buf, in);
        if(-1 ==in)
            break;
    }
    close(fd_s);
    close(fd_d);
    printf("File copied successfully.\n");
    return 0;
}