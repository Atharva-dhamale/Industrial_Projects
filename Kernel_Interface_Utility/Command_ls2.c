#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>


//      ./lsx           -i
//      argv[0]         argv[1]

//      argc=2


/*
            ALGORITHM


    Open Current Directory (".")
    Read all entries from that directory
    print the name of files
    close directory
*/


int main(int argc,char *argv[])
{
    int Option=0;

    //1 : ls -a
    //2 : ls -i

    Option=argc;

    if(argc==1)
    {
        Option=1;
    }
    else if(strcmp(argv[1],"-a")==0)
    {
        Option=1;
    }
    else if(strcmp(argv[1],"-i")==0)
    {
        Option=2;
    }
    else
    {
        printf("Error : There is no such option\n");
    }

    char *path=".";

    DIR *dp=NULL;

    dp=opendir(path);

    if(dp==NULL)
    {
        printf("Error : Unable to open directory\n");
        return -1;
    }

    struct dirent *dobj;

    while((dobj=readdir(dp))!=NULL)
    {
        printf("%s\n",dobj->d_name);

        if(Option==1)
        {
            printf("%s\n",dobj->d_name);
        }
        else if(Option==2)
        {
            printf("%ld%s\n",dobj->d_ino,dobj->d_name);
        }
    }

    closedir(dp);

    return 0;
}