#include<stdio.h>

int main(int argc,char *argv[])
{
    printf("Number of Command Line arguments are :%d\n",argc);

    int i=0;

    for(i=0;i<argc;i++)
    {
        printf("%s\n",argv[i]);
    }
    
    return 0;
}