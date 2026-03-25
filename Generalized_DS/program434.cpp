#include<iostream>

using namespace std;

class Arithmetic
{
    private:
        int No1,No2;

    public:
        Arithmetic(int A,int B)
        {
            this->No1=A;
            this->No2=B;
        }

        int Addition()
        {
            return No1+No2;
        }

        int Subtraction()
        {
            return No1-No2;
        }
};

int main()
{

    Arithmetic aobj(11,10);

    cout<<aobj.Addition()<<"\n";
    cout<<aobj.Subtraction()<<"\n";

    return 0;
}