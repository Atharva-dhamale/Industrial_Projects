/////////////////////////////////////////////////////////////////////
//          CLIENT APPLICATION
/////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdbool.h>

int ReadLine(int Sock,char *line,int max)
{
    int i=0;
    char ch='\0';
    int n=0;

    while(i<max-1)
    {
        n=read(Sock,&ch,1);

        if(n<=0)
        {
            break;
        }

        line[i++]=ch;

        if(ch=='\n')
        {
            break;
        }
    }   //End of While

    line[i]='\0';

    return i;

}       //End of ReadLine function

///////////////////////////////////////////////////////////////////////////////////////////////
//
//      CommandLine Argument Application
//
//      1st Argument :  IP Address
//      2nd Argument :  Port Number
//      3rd Argument :  Targeted File Name
//      4th Argument :  New File Name
//
//      ./client    127.0.0.1   9000        Demo.txt    A.txt
//      argv[0]     argv[1]     argv[2]     argv[3]     argv[4]
///////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
    int Sock=0;                 
    int Port=0;                 //argv[2]
    int iRet=0;

    char *ip=NULL;              //argv[1]
    char *FileName=NULL;        //argv[3]
    char *OutFileName=NULL;     //argv[4]

    char Header[64]={'\0'};

    struct sockaddr_in ServerAddr;
    

    if((argc<5)||(argc>5))
    {
        printf("Unable to proceed as invalid number of arguments\n");
        printf("Please provide :\n");
        printf("1) IP Address\n2) Port Number\n3) Targeted File Name\n4) New File Name\n");

        return -1;
    }

    //Store Command Line Arguments into the variables

    ip=argv[1];
    Port=atoi(argv[2]);
    FileName=argv[3];
    OutFileName=argv[4];


    /////////////////////////////////////////////////////
    //
    //      Step 1 : Create TCP Socket
    //
    /////////////////////////////////////////////////////

    Sock=socket(AF_INET,SOCK_STREAM,0);

    if(Sock<0)
    {
        printf("Unable to create the client Socket\n");
        return -1;
    }

    /////////////////////////////////////////////////////
    //
    //      Step 2 : Connect with Server
    //
    /////////////////////////////////////////////////////

    memset(&ServerAddr,0,sizeof(ServerAddr));

    ServerAddr.sin_family=AF_INET;
    ServerAddr.sin_port=htons(Port);
    

    //Convert IP address into binary format

    inet_pton(AF_INET,ip,&ServerAddr.sin_addr);

    iRet=connect(Sock,(struct sockaddr *) &ServerAddr,sizeof(ServerAddr));

    if(iRet==-1)
    {
        printf("Unable to connect with server\n");
        close(Sock);
        return -1;
    }

    /////////////////////////////////////////////////////
    //
    //      Step 3 : Senf  File Name
    //
    /////////////////////////////////////////////////////

    write(Sock,FileName,strlen(FileName));
    write(Sock,"\n",1);

    /////////////////////////////////////////////////////
    //
    //      Step 4 : Read the Header
    //
    /////////////////////////////////////////////////////


    iRet=ReadLine(Sock,Header,sizeof(Header));

    if(iRet<=0)
    {
        printf("Server gets disconnected abnormally\n");
        close(Sock);
        return -1;
    }

    long FileSize=0;

    sscanf(Header,"OK %ld",&FileSize);
    printf("File Size is : %ld\n",FileSize);


    /////////////////////////////////////////////////////
    //
    //      Step 5 : Create new File
    //
    /////////////////////////////////////////////////////

    int outfd=0;

    outfd=open(OutFileName,O_CREAT|O_WRONLY|O_TRUNC,0777);

    if(outfd<0)
    {
        printf("Unable to create downloaded file\n");
        return -1;
    }

    char Buffer[1024]={'\0'};
    long receive=0;
    long remaining=0;
    int n=0;
    int toRead=0;

    while(receive<FileSize)
    {
        remaining=FileSize-receive;

        if(remaining>1024)
        {
            toRead=1024;
        }
        else
        {
            toRead=remaining;
        }

        n=read(Sock,Buffer,toRead);

        write(outfd,Buffer,n);

        receive=receive+n;

    }   //End of While
    
    close(outfd);
    close(Sock);

    if(receive==FileSize)
    {
        printf("Download Complete...\n");
        return 0;
    }
    else
    {
        printf("Download failed..\n");
        return -1;
    }

    
    return 0;

}       //End of main