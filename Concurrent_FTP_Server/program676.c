#include<stdio.h>

int main(int argc,char *argv[])
{
    printf("Number of Command Line arguments are :%d\n",argc);

    if(argc!=5)
    {
        printf("Unable to proceed as invalid number of arguments\n");
        printf("Please provide :\n");
        printf("1) IP Address\n2) Port Number\n3) Targeted File Name\n4) New File Name\n");
        
        return -1;
    }

    printf("Executable name : %s\n",argv[0]);
    printf("IP Address : %s\n",argv[1]);
    printf("Port Number : %s\n",argv[2]);
    printf("Targeted File Name : %s\n",argv[3]);
    printf("New File Name : %s\n",argv[4]);
    
    return 0;
}