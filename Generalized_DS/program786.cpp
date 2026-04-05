
/////////////////////////////////////////
//Final code of Insertion Sort
/////////////////////////////////////////

#include<iostream>
using namespace std;

#define INC_ORDER 1
#define DEC_ORDER 2

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

    void BubbleSort();
    void BubbleSortEfficient();
    void BubbleSortEfficientX(int iOption);

    void SelectionSort();

    void InsertionSort();
    
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


// 21 15 18 16 11


void ArrayX :: BubbleSort()
{
    int i=0,j=0;
    int temp=0;
    int pass=0;
    int time=0;

    if(Sorted==true)            //Important filter
    {
        return;
    }

    time=1;

    for(i=0,pass=1;i<iSize-1;i++,pass++)          //Outer loop
    {
        for(j=0;j<iSize-1-i;j++,time++)    //Inner loop
        {
            if(Arr[j]>Arr[j+1])
            {
                temp=Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=temp;
            }
        }
        cout<<"\nData after Pass : "<<i+1<<"\n";
        Display();
    }
    cout<<"Number of passes for Bubble sort : "<<pass<<"\n";
    cout<<"Total Number of iterations : "<<time<<"\n";

    Sorted=true;
}


void ArrayX :: BubbleSortEfficient()
{
    int i=0,j=0;
    int temp=0;

    bool bFlag=false;

    /*if(Sorted==true)            //Important filter
    {
        return;
    }*/

    bFlag=true;

    for(i=0;(i<iSize-1) && (bFlag==true);i++)          //Outer loop
    {
        bFlag=false;

        for(j=0;j<iSize-1-i;j++)    //Inner loop
        {
            if(Arr[j]>Arr[j+1])
            {
                temp=Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=temp;

                bFlag=true;
            }
        }
        cout<<"\nData after Pass : "<<i+1<<"\n";
        Display();
    }
    cout<<"Number of passes for Bubble sort : "<<i<<"\n";

    Sorted=true;
}


//1 : Increasing
//2 : Decreasing
void ArrayX :: BubbleSortEfficientX(int iOption=INC_ORDER)
{
    int i=0,j=0;
    int temp=0;

    bool bFlag=false;

    if(iOption<1 || iOption>2)
    {
        cout<<"Invalid option for swapping\n";
        cout<<"1 : Increasing\n";
        cout<<"2 : Decreasing\n";
        return;
    }

    /*if(Sorted==true)            //Important filter
    {
        return;
    }*/

    bFlag=true;


    if(iOption==INC_ORDER)          //Increasing
    {

        for(i=0;(i<iSize-1) && (bFlag==true);i++)          //Outer loop
        {
            bFlag=false;


            
            for(j=0;j<iSize-1-i;j++)    //Inner loop
            {

                
                if(Arr[j]>Arr[j+1])
                {
                    temp=Arr[j];
                    Arr[j]=Arr[j+1];
                    Arr[j+1]=temp;

                    bFlag=true;
                }   
            }
            cout<<"\nData after Pass : "<<i+1<<"\n";
            Display();
        }
    }   //End of if

    else if(iOption==DEC_ORDER)         //Decreasing
    {
        for(i=0;(i<iSize-1) && (bFlag==true);i++)          //Outer loop
        {
            bFlag=false;


            
            for(j=0;j<iSize-1-i;j++)    //Inner loop
            {

                
                if(Arr[j]<Arr[j+1])
                {
                    temp=Arr[j];
                    Arr[j]=Arr[j+1];
                    Arr[j+1]=temp;

                    bFlag=true;
                }   
            }
            cout<<"\nData after Pass : "<<i+1<<"\n";
            Display();
        }
    }   //End of else if
    
    cout<<"Number of passes for Bubble sort : "<<i<<"\n";

    Sorted=true;
}


void ArrayX :: SelectionSort()
{
    int i=0,j=0,temp=0;
    int min_index=0;

    for(i=0;i<iSize-1;i++)
    {
        min_index=i;

        for(j=i+1;j<iSize;j++)
        {
            if(Arr[j]<Arr[min_index])
            {
                min_index=j;
            }
        }

        if(i != min_index)
        {
            temp=Arr[i];
            Arr[i]=Arr[min_index];
            Arr[min_index]=temp;
        }
        
    }
}

void ArrayX :: InsertionSort()
{
    int i=0,j=0;
    int selected=0;

    for(i=1;i<iSize;i++)
    {
        for(j=i-1 ,selected=Arr[i] ; (j>=0) && (Arr[j]>selected) ; j--)
        {
            Arr[j+1]=Arr[j];
        }
        Arr[j+1]=selected;
    }
}

int main()
{
    int iValue=0;
    
    cout<<"Enter the number of elements:";
    cin>>iValue;

    ArrayX aobj(iValue);
    aobj.Accept();

    cout<<"Data before sorting\n";
    aobj.Display();

    //1 : Increasing
    //2 : Decreasing

    //aobj.BubbleSortEfficientX(DEC_ORDER);
    //aobj.SelectionSort();
    aobj.InsertionSort();
    cout<<"Data after sorting\n";
    aobj.Display();




    return 0;
}
