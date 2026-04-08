/////////////////////////////////////////////////////////////////////
//          SERVER APPLICATION
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

///////////////////////////////////////////////////////////////////////////////////////////////
//
//      CommandLine Argument Application
//
//      1st Argument : Port Number
//
//      argv[0]=./server
//      argv[1]=Port Number
//
///////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
    int ServerSocket=0;
    int ClientSocket=0;
    int Port=0;
    int iRet=0;
    pid_t pid=0;

    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;

    socklen_t AddrLen=sizeof(ClientSocket);

    if((argc<2)||(argc>2))
    {
        printf("Unable to proceed as invalid number of arguments\n");
        printf("Please provide the port number\n");
        return -1;
    }

    //Port Number of Server
    Port=atoi(argv[1]);


    /////////////////////////////////////////////////////
    //
    //      Step 1 : Create TCP Socket
    //
    /////////////////////////////////////////////////////


    ServerSocket=socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocket<0)
    {
        printf("Unable to create server socket\n");
        return -1;
    }



    /////////////////////////////////////////////////////
    //
    //      Step 2 : Bind socket to IP and Port
    //
    /////////////////////////////////////////////////////


    memset(&ServerAddr,0,sizeof(ServerAddr));

    //Initialise the structure
    
    ServerAddr.sin_family=AF_INET;
    ServerAddr.sin_port=htons(Port);
    ServerAddr.sin_addr.s_addr=INADDR_ANY;

    iRet=bind(ServerSocket,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr));

    if(iRet==-1)
    {
        printf("Unable to bind\n");
        close(ServerSocket);
        return -1; 
    }


    /////////////////////////////////////////////////////
    //
    //      Step 3 : Listen for Client Connection
    //
    /////////////////////////////////////////////////////


    iRet=listen(ServerSocket,11);

    if(iRet==-1)
    {
        printf("Server Unable to listen the request\n");
        close(ServerSocket);
        return -1;
    }

    printf("Server is running on port : %d\n",Port);


    /////////////////////////////////////////////////////
    //
    //  Loop which accepts client request continuously
    //
    /////////////////////////////////////////////////////


    //Loop to accept multiple client request

    while(1)
    {

        /////////////////////////////////////////////////////
        //
        //      Step 4 : Accepts the Client Connection
        //
        /////////////////////////////////////////////////////

        memset(&ClientAddr,0,sizeof(ClientAddr));

        printf("Server is waiting for client request\n");

        ClientSocket=accept(ServerSocket,(struct sockaddr *) &ClientAddr,&AddrLen);

        if(ClientSocket<0)
        {
            printf("Unable to accept client request\n");
            continue;   //Used for while
        }

        printf("Client gets connected : %s\n",inet_ntoa(ClientAddr.sin_addr));


        /////////////////////////////////////////////////////////////////
        //
        //      Step 5 : Create new process to handle Client Request
        //
        /////////////////////////////////////////////////////////////////


        pid=fork();

        if(pid<0)
        {
            printf("Unable to create new process for client request\n");

            close(ClientSocket);

            continue;

        }

        //New process gets created for client

        if(pid==0)
        {
            printf("New process is created for client Request\n");
            close(ServerSocket);
        }

    }    //End of While

    
    return 0;

}       //End of main