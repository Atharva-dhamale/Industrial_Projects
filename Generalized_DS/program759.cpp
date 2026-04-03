#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

    ArrayX(int No);
    ~ArrayX();
    void Accept();
    void Display();
    bool CheckSorted();
    
};

ArrayX :: ArrayX(int No)
{
    cout<<"Inside Constructor\n";
    iSize=No;
    Arr=new int[iSize];
    Sorted=true;
}
ArrayX :: ~ArrayX()
{
    cout<<"Inside Destructor\n";
    delete []Arr;

}

void ArrayX :: Accept()
{
    int iCnt=0;

    cout<<"Enter the elements :\n";
    cin>>Arr[iCnt];

    for(iCnt=1;iCnt<iSize;iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt-1]>Arr[iCnt])
        {
            Sorted=false;
        }
    }

    //Sorted=CheckSorted();
}
void ArrayX :: Display()
{
    int iCnt=0;

    cout<<"Elements of the array are:\n";
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}



bool ArrayX :: CheckSorted()
{
    int i=0;
    bool bFlag=true;

    for(i=0;i<iSize-1;i++)
    {
        if(Arr[i]>Arr[i+1])
        {
            bFlag=false;
            break;
        }
    }
    return bFlag;
}


int main()
{
    int iValue=0;
    
    cout<<"Enter the number of elements:";
    cin>>iValue;

    ArrayX aobj(iValue);
    aobj.Accept();
    aobj.Display();


    return 0;
}
