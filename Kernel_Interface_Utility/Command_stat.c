#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>


//      ./statx    FileName
//      argv[0]     argv[1]

//      argc=2



/*
            ALGORITHM


    Accept file name from command line
    Call Access to check existance of file
    Call Stat() to get files metadata
    Display the metadata
*/



int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("Error : Insufficient arguments\n");
        printf("Use Command as : ./statx\tFileName\n");
        return -1;
    }

    if(access(argv[1],F_OK)==0)
    {
        struct stat sobj;
        int iRet=0;

        iRet=stat(argv[1],&sobj);

        if(iRet==-1)
        {
            printf("Error : Unable to fetch Statistical information\n");
            return -1;
        }

        printf("File name : %s\n",argv[1]);
        printf("File Size : %ld\n",sobj.st_size);
        printf("Inode number : %ld\n",(long)sobj.st_ino);
    }

    else
    {
        printf("File not found\n");
        return -1;
    }

    return 0;
}