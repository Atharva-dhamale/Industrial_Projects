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

void DisplayPermission(mode_t m)
{
    char Arr[11]="-----------";

    if(S_ISDIR(m))Arr[0]='d';
    if(S_ISLNK(m))Arr[0]='l';

    //Regular File permissions
    if(m & S_IRUSR)Arr[1]='r';
    if(m & S_IWUSR)Arr[2]='w';
    if(m & S_IXUSR)Arr[3]='x';

    if(m & S_IRGRP)Arr[4]='r';
    if(m & S_IWGRP)Arr[5]='w';
    if(m & S_IXGRP)Arr[6]='x';

    if(m & S_IROTH)Arr[7]='r';
    if(m & S_IWOTH)Arr[8]='w';
    if(m & S_IXOTH)Arr[9]='x';

    printf("File Permission : %s\n",Arr);
}

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

        DisplayPermission(sobj.st_mode);
    }

    else
    {
        printf("File not found\n");
        return -1;
    }

    return 0;
}