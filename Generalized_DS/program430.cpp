#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;


//Use of this->


class SinglyLL
{
    public:
        PNODE first;
        int iCount;

        SinglyLL()
        {
            cout<<"Object of Singly LL gets created\n";
            this->first=NULL;
            this->iCount=0;
        }



        void InsertFirst(int no)                
        {
            PNODE newn=NULL;

            newn=new NODE;

            newn->data=no;
            newn->next=NULL;

    
            newn->next=this->first;
            this->first=newn;

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn=NULL;
            PNODE temp=NULL;

            newn=new NODE;

            newn->data=no;
            newn->next=NULL;

            if(this->iCount==0)               //Updated
            {
                this->first=newn;
            }
            else
            {
                temp=this->first;

                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newn;
            }
            this->iCount++;
        }
        
        void DeleteFirst()
        {
            PNODE temp=NULL;

            if(this->first==NULL)
            {
                return;
            }
            else if(this->first->next==NULL)          //this->iCount==1;
            {
                delete this->first;
                this->first=NULL;
            }
            else
            {
               temp=this->first;
               this->first=this->first->next;
               delete temp; 
            }
            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp=NULL;

            if(this->first==NULL)
            {
                return;
            }
            else if(this->first->next==NULL)          //iCount==1;
            {
                delete this->first;
                this->first=NULL;
            }
            else
            {
                temp=this->first;

                while(temp->next->next!=NULL)
                {
                    temp=temp->next;
                }
                delete temp->next;
                temp->next=NULL;
            }
            this->iCount--;
        }

        
        void Display()
        {
            PNODE temp=NULL;

            temp=this->first;
            int iCnt=0;

            for(iCnt=1;iCnt<=this->iCount;iCnt++)
            {
                cout<<"| "<<temp->data<<" |->";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return this->iCount;
        }

        void InsertAtPos(int no,int pos)
        {
            PNODE newn=NULL;
            PNODE temp=0;
            int iCnt=0;

            if((pos<1)||(pos>iCount+1))
            {
                cout<<"Invalid position\n";
                return;
            }  
            if(pos==1)
            {
                this->InsertFirst(no);
            }
            else if(pos==this->iCount+1)
            {
                this->InsertLast(no);
            }
            else
            {
                
                newn=new NODE;

                newn->data=no;
                newn->next=NULL;

                temp=this->first;
                for(iCnt=1;iCnt<pos-1;iCnt++)
                {
                    temp=temp->next;
                }

                newn->next=temp->next;
                temp->next=newn;

                this->iCount++;
            }
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp=0;
            PNODE target=NULL;
            int iCnt=0;

            if((pos<1)||(pos>iCount))
            {
                cout<<"Invalid position\n";
                return;
            }  
            if(pos==1)
            {
                this->DeleteFirst();
            }
            else if(pos==iCount)
            {
                this->DeleteLast();
            }
            else
            {

                temp=this->first;
                for(iCnt=1;iCnt<pos-1;iCnt++)
                {
                    temp=temp->next;
                }

                target=temp->next;
                temp->next=target->next;
                delete target;

               
                this->iCount--;
            }
        }

};

int main()
{
    SinglyLL obj;
    int iRet=0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    //obj.first=NULL;               Risky syntax
    //obj.iCount=0;                 Risky syntax            

    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";


    return 0;
}