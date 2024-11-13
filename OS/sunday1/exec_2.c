#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
    pid_t id;
    unsigned char cmd[128],ext[128],bin[128]="/bin/";
    if(argc != 1)
    {
        printf("Command not entered\n");
        exit(1);
    }
    // while(1)
    {
        printf("Enter the command\n");

        printf("%s",cmd);
        scanf("%s",cmd);
        strcat(bin,cmd);
        
        id=fork();
        if(id== -1)
        {
            perror("fork");
            exit(1);
        }
        if(0==id)
        {
            execl((const char*)bin,"",NULL);
        }
        else
        {}
    }
}