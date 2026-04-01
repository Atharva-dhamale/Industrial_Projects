
///////////////////////////////////////////////////////////////////////
//          Generalized Data Structure Library
///////////////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------------------------
    Type                Name of Class for node              Name of Class for Functionality
-----------------------------------------------------------------------------------------------------

    Singly Linear           SinglyLLLnode                       SinglyLLL       Done
    Singly Circular         SinglyCLLnode                       SinglyCLL
    Doubly Linear           DoublyLLLnode                       DoublyLLL       Done
    Doubly Circular         DoublyCLLnode                       DoublyCLL
    Stack                   Stacknode                           Stack           Done
    Queue                   Queuenode                           Queue           Done
-----------------------------------------------------------------------------------------------------
*/




#include<iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////
//          Singly Linear LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>

class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};


template<class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);

        void InsertLast(T);
        
        void DeleteFirst();

        void DeleteLast();
 
        void Display();

        int Count();

        void InsertAtPos(T,int);

        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"\n\n-------------------------Singly Linear Linked List-------------------------\n\n";
    this->first=NULL;
    this->iCount=0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Atharva Kailash Dhamale
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::InsertFirst(T no)                
{
    SinglyLLLnode<T> * newn=NULL;

    newn=new SinglyLLLnode<T>(no);


    newn->next=this->first;
    this->first=newn;

    this->iCount++;
}

template<class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> * newn=NULL;
    SinglyLLLnode<T> * temp=NULL;

    newn=new SinglyLLLnode<T>(no);

    if(this->iCount==0)    
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

template<class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> * temp=NULL;

    if(this->first==NULL)
    {
        return;
    }
    else if(this->first->next==NULL)  
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

template<class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> * temp=NULL;

    if(this->first==NULL)
    {
        return;
    }
    else if(this->first->next==NULL)  
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

template<class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> * temp=NULL;

    temp=this->first;
    int iCnt=0;

    for(iCnt=1;iCnt<=this->iCount;iCnt++)
    {
        cout<<"| "<<temp->data<<" |->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

template<class T>
void SinglyLLL<T>::InsertAtPos(T no,int pos)
{
    SinglyLLLnode<T> * newn=NULL;
    SinglyLLLnode<T> * temp=NULL;
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
        
        newn=new SinglyLLLnode<T>(no);

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

template<class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp=0;
    SinglyLLLnode<T> * target=NULL;
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



///////////////////////////////////////////////////////////////////////
//          Doubly Linear LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>

class DoublyLLLnode 
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
            this->prev=NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> *first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);

        void InsertLast(T);

        void InsertAtPos(T,int);

        void DeleteFirst();

        void DeleteLast();

        void DeleteAtPos(int);

        void Display();

        int Count();

};

template<class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"\n\n-------------------------Doubly Linear Linked List-------------------------\n\n";

    this->first=NULL;
    this->iCount=0;
}

template<class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn=NULL;

    newn=new DoublyLLLnode<T>(no);

    if(this->first==NULL)
    {
        this->first=newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev=newn;
        this->first=newn;
    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn=NULL;
    DoublyLLLnode<T> *temp=NULL;

    newn=new DoublyLLLnode<T>(no);

    if(this->first==NULL)
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
       newn->prev=temp;

    }
    this->iCount++;
}

template<class T>
void DoublyLLL<T>::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp=NULL;
    DoublyLLLnode<T> *newn=NULL;
    int iCnt=0;

    if((pos<1)||pos>this->iCount+1)
    {
        cout<<"Invalid Position\n";
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
        newn=new DoublyLLLnode<T>(no);

        temp=this->first;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

        this->iCount++;
    }
}

template<class T>
void DoublyLLL<T>::DeleteFirst()
{

    if(this->first==NULL)                
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first->next==NULL)         
    {
        delete this->first;
        this->first=NULL;
    }
    else                                      
    {
        this->first=this->first->next;
        delete this->first->prev;
        this->first->prev=NULL;
    }

    this->iCount--;
}

template<class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp=NULL;

    if(this->first==NULL)      
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first->next==NULL) 
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

template<class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp=NULL;
    int iCnt=0;

    if((pos<1)||pos>this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    if(pos==1)
    {
        this->DeleteFirst();
    }
    else if(pos==this->iCount)
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
        
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;

        this->iCount--;
    }
}

template<class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> *temp=NULL;
    temp=this->first;

    cout<<"\nNULL<=>";
    while(temp!=NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}




///////////////////////////////////////////////////////////////////////
//          Singly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>

class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode *next;

        SinglyCLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};


template <class T>
class SinglyCLL
{
    private:
            SinglyCLLnode<T> *first;
            SinglyCLLnode<T> *last;
            int iCount;

    public:
            SinglyCLL();

            void InsertFirst(T no);

            void InsertLast(T no);

            void DeleteFirst();

            void DeleteLast();

            void Display();

            int Count();

            void InsertAtPos(T no,int pos);

            void DeleteAtPos(int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"\n\n-------------------------Singly Circular Linked List-------------------------\n\n";
    this->first=NULL;
    this->last=NULL;
    this->iCount=0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn=new SinglyCLLnode<T>(no);
    

    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=this->last=newn;

    }
    else
    {
        newn->next=this->first;
        this->first=newn;
    }
    this->last->next=this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn=new SinglyCLLnode<T>(no);
    
    
    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=this->last=newn;


    }
    else
    {
        this->last->next=newn;
        this->last=newn;  
    }

    this->last->next=this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    SinglyCLLnode<T> *temp=NULL;

    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
    }
    else
    {
        temp=this->first;
        this->first=this->first->next;
        delete temp;  

        this->last->next=this->first;
    }
    
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> *temp=NULL;


    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
    }
    else
    {
        temp=first;

        while(temp->next!=last)
        {
            temp=temp->next;
        }
        
        delete last;
        last=temp;

        this->last->next=this->first;
    }
    
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::Display()
{
    SinglyCLLnode<T> *temp=NULL;
    temp=first;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp=temp->next;
    }while(temp!=first);

    cout<<"\n";

    
}

template <class T>
int SinglyCLL<T>::Count()
{

    return iCount;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no,int pos)
{
    SinglyCLLnode<T> *newn=new SinglyCLLnode<T>(no);
    SinglyCLLnode<T> *temp=NULL;
    int iCnt=0;

    if((pos<1)||(pos>this->iCount+1))
    {
        cout<<"Inavlid position";
        return;
    }
    if(pos==1)
    {
        this->InsertFirst(no);
    }
    else if(pos==iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {

        temp=this->first;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        this->last->next=this->first;
        this->iCount++;
    }

}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    int iCnt=0;
    SinglyCLLnode<T> *temp=NULL;
    SinglyCLLnode<T> *target=NULL;

    if((pos<1)||(pos>this->iCount))
    {
        cout<<"Inavlid position";
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
        
        this->last->next=this->first;
        this->iCount--;
    }
}


///////////////////////////////////////////////////////////////////////
//          Doubly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////////



#pragma pack(1)

template<class T>
class DoublyCLLnode
{
    public:

        T data;
        struct DoublyCLLnode *next;
        struct DoublyCLLnode *prev;

        DoublyCLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
            this->prev=NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
            DoublyCLLnode<T> *first;
            DoublyCLLnode<T> *last;
            int iCount;
    public:
            DoublyCLL();

            void InsertFirst(T no);

            void InsertLast(T no);

            void DeleteFirst();

            void DeleteLast();

            void Display();

            int Count();

            void InsertAtPos(T no,int pos);  

            void DeleteAtPos(int pos);

            
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"\n\n-------------------------Doubly Circular Linked List-------------------------\n\n";
    this->first=NULL;
    this->last=NULL;
    this->iCount=0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn=new DoublyCLLnode<T>(no);

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=newn;
        this->last=newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev=newn;
        this->first=newn;

    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn=new DoublyCLLnode<T>(no);

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=newn;
        this->last=newn;
    }
    else
    {
        this->last->next=newn;
        newn->prev=this->last;
        this->last=newn;
    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount++; 
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
    }
    else
    {
        this->first=this->first->next;
        delete this->first->prev;
    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount--; 
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
    }
    else
    {
        this->last=this->last->prev;
        delete this->last->next;
    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount--;
}

template<class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode<T> *temp=NULL;
    temp=this->first;

    do
    {
        cout<<"| "<<temp->data<<"| <=>";
        temp=temp->next;
    }while(temp!=this->first);
    cout<<"\n";
}

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    DoublyCLLnode<T> *newn=new DoublyCLLnode<T>(no);
    DoublyCLLnode<T> *temp=NULL;
    int iCnt=0;

    if((pos<1)||(pos>iCount+1))
    {
        cout<<"Invalid position";
        return;
    }
    if(pos==1)
    {
        this->InsertFirst(no);
    }
    else if(pos==iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        temp=this->first;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;

        this->last->next=this->first;
        this->first->prev=this->last;
        this->iCount--;
    }
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp=NULL;
    int iCnt=0;

    if((pos<1)||(pos>iCount))
    {
        cout<<"Invalid position";
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
        
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;

        this->last->next=this->first;
        this->first->prev=this->last;
        this->iCount--;
    }
}



///////////////////////////////////////////////////////////////////////
//          Stack using Generic Approach
///////////////////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);

        T pop();

        T peep();

        void Display();

        int Count();
};

template<class T>
Stack<T>::Stack()
{
    cout<<"\n\n----------------------------Stack----------------------------\n\n";
    this->first=NULL;
    this->iCount=0;
}

template<class T>
void Stack<T>::push(T no)
{
    Stacknode<T> *newn=NULL;
    newn=new Stacknode<T>(no);

    newn->next=this->first;
    this->first=newn;

    this->iCount++;
}

template<class T>
T Stack<T>::pop()
{
    T Value=0;
    Stacknode<T> *temp=this->first;

    if(this->first==NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value=this->first->data;

    this->first=this->first->next;
    delete temp;

    this->iCount--;

    return Value;

}

template<class T>
T Stack<T>::peep()
{
    T Value=0;

    if(this->first==NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value=this->first->data;

    return Value;
}

template<class T>
void Stack<T>::Display()
{
    Stacknode<T> *temp=this->first;

    if(this->first==NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }
    while(temp!=NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp=temp->next;
    }
}

template<class T>
int Stack<T>::Count()
{
    return this->iCount;
}


///////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
///////////////////////////////////////////////////////////////////////


#pragma pack(1)

template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();

        void enqueue(T);

        T dequeue();

        void Display();

        int Count();
};

template<class T>
Queue<T>::Queue()
{
    cout<<"\n\n----------------------------Queue----------------------------\n\n";
    this->first=NULL;
    this->last=NULL;
    this->iCount=0;
}

template<class T>
void Queue<T>::enqueue(T no)
{
    Queuenode<T> *newn=NULL;
    newn=new Queuenode<T>(no);

    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=newn;
        this->last=newn;
    }
    else
    {
        this->last->next=newn;
        this->last=newn;
    }

    this->iCount++;
}

template<class T>
T Queue<T>::dequeue()
{
    T Value=0;
    Queuenode<T> *temp=this->first;

    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value=this->first->data;

    this->first=this->first->next;
    delete temp;

    this->iCount--;

    return Value;

}


template<class T>
void Queue<T>::Display()
{
    Queuenode<T> *temp=this->first;

    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Queue is empty\n";
        return;
    }
    while(temp!=NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp=temp->next;
    }
    cout<<"\n";
}

template<class T>
int Queue<T>::Count()
{
    return this->iCount;
}



/////////////////////////////////////////   End of Library  /////////////////////////////////////////////////////////

int main()
{
    SinglyLLL<int> *obj=new SinglyLLL<int>();
    int iRet=0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet=obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet=obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteFirst();

    obj->Display();

             

    iRet=obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();
    iRet=obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->InsertAtPos(105,4);

    obj->Display();
    iRet=obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet=obj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    delete obj;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *dobj=new DoublyLLL<char>();

    dobj->InsertFirst('a');
    dobj->InsertFirst('b');
    dobj->InsertFirst('c');
    dobj->Display();
    cout<<"Number of elemnts are :"<<dobj->Count()<<"\n";

    dobj->InsertLast('x');
    dobj->InsertLast('y');
    dobj->InsertLast('z');
    dobj->Display();
    cout<<"Number of elemnts are :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Number of elemnts are :"<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Number of elemnts are :"<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);
    dobj->Display();
    cout<<"Number of elemnts are :"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"Number of elemnts are :"<<dobj->Count()<<"\n";

    delete dobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SinglyCLL<int> *scobj=new SinglyCLL<int>();


    scobj->InsertFirst(43);
    scobj->InsertFirst(93);
    scobj->InsertFirst(27);
    scobj->Display();
    cout<<"Number of nodes are:"<<scobj->Count()<<"\n";

    scobj->InsertLast(84);
    scobj->InsertLast(31);
    scobj->InsertLast(25);
    scobj->Display();
    cout<<"Number of nodes are:"<<scobj->Count()<<"\n";

    scobj->DeleteFirst();
    scobj->Display();
    cout<<"Number of nodes are:"<<scobj->Count()<<"\n";

    scobj->DeleteLast();
    scobj->Display();
    cout<<"Number of nodes are:"<<scobj->Count()<<"\n";

    scobj->InsertAtPos(10,3);
    scobj->Display();
    cout<<"Number of nodes are:"<<scobj->Count()<<"\n";

    scobj->DeleteAtPos(4);
    scobj->Display();
    cout<<"Number of nodes are:"<<scobj->Count()<<"\n";

    delete scobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    DoublyCLL<int> *dcobj=new DoublyCLL<int>();

    dcobj->InsertFirst(27);
    dcobj->InsertFirst(93);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->InsertLast(84);
    dcobj->InsertLast(31);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(35,3);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(2);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    Stack<char> *sobj=new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');
    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Return value of peep is :"<<sobj->peep()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";


    sobj->push('e');
    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    delete sobj;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Queue<double> *qobj=new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";


    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";


    qobj->enqueue(121.56789);
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    delete qobj;

    
    return 0;
}
