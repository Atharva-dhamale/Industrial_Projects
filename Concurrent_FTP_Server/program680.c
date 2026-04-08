#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("PID of Running process : %d\n",getpid());
    printf("PID of Parent process : %d\n",getppid());

    return 0;
}