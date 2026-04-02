#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

    ArrayX(int No)
    {
        cout<<"Inside Constructor\n";
        iSize=No;
        Arr=new int[iSize];
    }
    ~ArrayX()
    {
        cout<<"Inside Destructor\n";
        delete []Arr;

    }

    void Accept()
    {
        int iCnt=0;

        cout<<"Enter the elements :\n";

        for(iCnt=0;iCnt<iSize;iCnt++)
        {
            cin>>Arr[iCnt];
        }
    }
    void Display()
    {
        int iCnt=0;

        cout<<"Elements of the array are:\n";
        for(iCnt=0;iCnt<iSize;iCnt++)
        {
            cout<<Arr[iCnt]<<"\t";
        }
        cout<<"\n";
    }
};

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
