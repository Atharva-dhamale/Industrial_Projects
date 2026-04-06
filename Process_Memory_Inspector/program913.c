#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


void GetSectionType(char *details,char *perms,char *section)
{
    if(strcmp(details,"[heap]")==0)
    {
        strcpy(section,"HEAP");
    }
    else if(strcmp(details,"[stack]")==0)
    {
        strcpy(section,"STACK");
    }
    else if(strcmp(details,"[vdso]")==0)
    {
        strcpy(section,"VDSO");
    }
    else if(strcmp(details,"[vvar]")==0)
    {
        strcpy(section,"VVAR");
    }
    else if(perms[2]=='x')
    {
        strcpy(section,"TEXT");
    }
    else if(perms[1]=='w')
    {
        strcpy(section,"DATA");
    }
    else
    {
        strcpy(section,"OTHER");
    }
}

void ShowMemoryLayout(int pid)
{
    FILE *fp=NULL;
    char line[80];
    char filename[100];

    sprintf(filename,"/proc/%d/maps",pid);
    printf("Accesing the file : %s\n",filename);

    fp=fopen(filename,"r");
    
    if(fp==NULL)
    {
        printf("Unable to access system file\n");
        return;
    }

    printf("-------------------------------------------------------------------\n");
    printf("---------------------------- Memory Layout ------------------------\n");
    printf("-------------------------------------------------------------------\n");

    printf("----- header ------\n");

    char Address[100],perms[10],offset[20],dev[20],details[300]="";

    unsigned long inode;
    unsigned long start,end;
    unsigned long sizekb;
    char section[50];

    int Ret=0;

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        
        Ret=sscanf(line,"%s %s %s %s %lu %[^\n]",Address,perms,offset,dev,&inode,details);

        if(Ret>=5)
        {
            sscanf(Address,"%lx-%lx",&start,&end);
            sizekb=(end-start)/1024;

            GetSectionType(details,perms,section);

            if(strlen(details)==0)
            {
                strcpy(details,"Anonymous");
            }
            printf("%lx %lx %lu %s %s %s\n",start,end,sizekb,perms,section,details);
        }

        printf("-------------------------------------------------------------------\n");
        


    }
    fclose(fp);
}

void ShowProcessInformation(int pid)
{
    FILE *fp=NULL;
    char line[80];
    char filename[100];

    sprintf(filename,"/proc/%d/status",pid);
    printf("Accesing the file : %s\n",filename);

    fp=fopen(filename,"r");
    
    if(fp==NULL)
    {
        printf("Unable to access system file\n");
        return;
    }

    printf("-------------------------------------------------------------------\n");
    printf("----------------------- Process Information -----------------------\n");
    printf("-------------------------------------------------------------------\n");

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        if(strncmp(line,"Name:",5)==0 ||
            strncmp(line,"Pid:",4)==0 ||
            strncmp(line,"State:",6)==0 ||
            strncmp(line,"Threads:",8)==0)
            {
                printf("%s\n",line);
            }  
            
    }

    printf("-------------------------------------------------------------------\n");

}

int main()
{
    int pid=0;
    

    printf("-------------------------------------------------------------------\n");
    printf("------------------ Marvellous Process Inspector -------------------\n");
    printf("-------------------------------------------------------------------\n");

    printf("Enter the pid of process that you want to inspect\n");
    scanf("%d",&pid);

    if(pid<=0)
    {
        printf("Invalid pid\n");
        return -1;
    }

    ShowProcessInformation(pid);
    ShowMemoryLayout(pid);
    
    return 0;
}


/*
    Text / Code
    Data
    Stack
    VDSO -      Vitual Dynamic shared object
    VVAR -      Vitual variables
    VSYSCALL -  Virtual System call page
    Other -     Other memory regions

*/