#include<stdio.h>
#include<unistd.h>
int main()
{
 execl("/usr/bin/cat","cat","exec_1.c",NULL);
 printf("\n");
 return 0;   
}