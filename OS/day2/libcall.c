#include<stdio.h>
#define BUF_SIZE 64
int main()
{
    FILE *src,*dest;
    size_t in,out;
    char buf[BUF_SIZE];
    src=fopen("src.txt","r");
    if(NULL==src)
    {
        // printf("ERROR IN OPENING THE FILE\n");
        perror("Error while opening the file\n");
    }
    dest=fopen("dest.txt","w");
    if(dest<0)
    {
        printf("ERROR IN OPENING THE FILE\n");
    }
    while (1)
    {
    in=fread(buf,1,BUF_SIZE,src);
    if(0==in)
    break;
    out=fwrite(buf,1,in,dest);
    if(0==out)
    break;
    }
printf("Files are copied\n");
fclose(src);
fclose(dest);

}