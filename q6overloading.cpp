/*
Define a class named MyInteger that stores an integer and 
has functions to get and set the intergers value. 
Then, overload the [] operator so that 
the index returns the digit in position i, 
where i = 0 is the least-significant digit. 
If no such digit exists then -1 should be returned.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class MyInteger
{
public:
    int get(){ return val; }
    void set(int bInteger){ val = bInteger; }
    int operator[](int x);
    friend istream& operator>> (istream& inputStream, MyInteger& x);
private:
    int val;
};

int main( )
{
    MyInteger integer;
    
    cin >> integer;
    cout<<"MyInteger: "<<integer.get()<<endl;
    int i;   /*position*/
    cout<<"Enter the reference from zero to fine digit>>";
    cin>>i;
    
    if(integer[i]==-1)
        cout<<"The integer doesn't exit.\n";
    else
        cout<<"The digit is: "<<integer[i];
    
    return 0;
}
istream& operator>> (istream& inputStream, MyInteger& x)
{
    int v;
    inputStream >> v;
    x.set(v);
    return inputStream;
}
int MyInteger::operator[](int x)
{
    int ten;
    for (ten = 10; x!=0 ; x--)
        ten *= 10;
    int digit = (val%ten) / (ten / 10);
    return val >= ten/10 ?  digit:-1;
}