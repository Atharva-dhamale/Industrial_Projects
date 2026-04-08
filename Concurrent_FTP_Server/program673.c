
//-------------------------------------------
//      CLIENT CODE
//-------------------------------------------

#include<stdio.h>       //printf, scanf
#include<stdlib.h>      //malloc, free
#include<string.h>      //memset, memcmp

#include<unistd.h>      //close, read, write
#include<fcntl.h>       //creat, unlink

#include<sys/socket.h>  //socket, bind, listen, accept, connect
#include<netinet/in.h>  //sockaddr_in, htons

#include<arpa/inet.h>



int main()
{
    int ServerSocketFD=0;
    int iRet=0;
    int Port=11000;

    struct sockaddr_in ServerAddr;

    char Buffer[1024]={'\0'};


    //Step 1 : Create TCP Socket

    ServerSocketFD=socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocketFD<0)
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("Socket gets created succesfully with fd : %d\n",ServerSocketFD);

    //Step 2 :Connect with Server

    memset(&ServerAddr,0,sizeof(ServerAddr));

    ServerAddr.sin_family=AF_INET;
    ServerAddr.sin_port=htons(Port);

    inet_pton(AF_INET,"127.0.0.1",&ServerAddr.sin_addr);

    iRet=connect(ServerSocketFD,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr));

    if(iRet==-1)
    {
        printf("Unable to connect with Server\n");
        return -1;
    }

    printf("Client Succesfully connected with Server\n");

    //Step 3 : Read the data from Server

    iRet=read(ServerSocketFD,Buffer,sizeof(Buffer)-1);

    if(iRet<=0)
    {
        printf("Unable to read the data from Server\n");
        return -1;
    }

    printf("Data from Server is : %s\n",Buffer);

    //Step 4 : Close all Resources

    close(ServerSocketFD);

    printf("Terminating the Client Application\n");

    
    return 0;
}