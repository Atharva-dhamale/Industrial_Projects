#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t pid=0;

    pid=fork();

    if(pid<0)
    {
        printf("Unable to create child process\n");
        return -1;
    }

    if(pid==0)
    {
        printf("Child Process gets created succesfully\n");
    }

    return 0;
}