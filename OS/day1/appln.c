#include<stdio.h>
#include "type.h"
int main()
{
    int x,y;
    x=10;
    y=20;
    printf("SUM is %d\n",sum(x,y));
    printf("Difference is %d\n",differ(x,y));
    printf("Prodeuct is %d\n",pro(x,y));
    printf("PID IS:%d",getpid());
}