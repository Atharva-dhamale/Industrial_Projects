
//-------------------------------------------
//      SERVER CODE
//-------------------------------------------

#include<stdio.h>       //printf, scanf
#include<stdlib.h>      //malloc, free
#include<string.h>      //memset, memcmp

#include<unistd.h>      //close, read, write
#include<fcntl.h>       //creat, unlink

#include<sys/socket.h>  //socket, bind, listen, accept, connect
#include<netinet/in.h>  //sockaddr_in, htons


/*

    struct sockaddr
    {
        sa_family_t sa_family;
        char sa_data[14];
    };

*/

int main()
{
    int iRet=0;
    int Port=11000;
    int ServerSocket=0;
    int ClientSocketFD=0;

    struct sockaddr_in ServerAddr;
    
    char *message="Jay Ganesh from server\n";
    
    //Step 1 : Create TCP (Transmition control protocol) Socket

    ServerSocket=socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocket<0)
    {
        printf("Unable to create socket\n");
        return -1;
    }
    printf("Socket gets created succesfully with fd :%d\n",ServerSocket);

    //Step 2: Attach the Socket to IP (Internet protocol) address and Port number

    //Set memory to 0
    memset(&ServerAddr,0,sizeof(ServerAddr));

    ServerAddr.sin_family=AF_INET;
    ServerAddr.sin_addr.s_addr=INADDR_ANY;
    ServerAddr.sin_port=htons(Port);

    iRet=bind(ServerSocket,(struct sockaddr*) &ServerAddr,sizeof(ServerAddr));

    if(iRet==-1)
    {
        printf("Bind system call failed\n");
        close(ServerSocket);
        return -1;
    }
    printf("Bind operation with socket is succesfull\n");

    //Step 3 : Mark the Socket as a active Socket

    iRet=listen(ServerSocket,11);       //11 request accept the listen system call

    if(iRet==-1)
    {
        printf("Unable to convert socket in listen mode\n");
        return -1;
    }
    printf("Server is live at port : %d\n",Port);

    //Step 4 : Accept new Socket Request

    ClientSocketFD=accept(ServerSocket,NULL,NULL);

    if(ClientSocketFD==-1)
    {
        printf("Unable to accept request from client\n");
        close(ServerSocket);
        return -1;
    }
    printf("Request accepted by Server\n");

    //Step 5 : Send message to Client

    write(ClientSocketFD,message,strlen(message));

    //Step 6 : Close all resources

    close(ClientSocketFD);
    close(ServerSocket);

    printf("Terminating the Server application\n");
    
    return 0;
}