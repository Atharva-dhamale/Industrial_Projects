#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>


//      ./rmx       FileName
//      argv[0]     argv[1]

//      argc=2



/*
            ALGORITHM


    Call the System call unlink
*/



int main(int argc,char *argv[])
{

    if(argc!=2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use Command as : ./rmx\tFileName\n");
        return -1;
    }

    if(access(argv[1],F_OK)==0)
    {
        if(unlink(argv[1])==-1)
        {
            printf("Error : Unable to delete\n");
            return -1;
        }
        else
        {
            printf("File deleted succesfully\n");
        }
    }
    else
    {
        printf("Error : No such file or directory\n");
        return -1;
    }
    
    return 0;
}