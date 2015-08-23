#include <iostream>
#include <cstdlib>
using namespace std;

class PrimeNumber
{
public:
    PrimeNumber() : pNum(1) {}
    PrimeNumber(int setNum) : pNum(setNum) {}
    int getNum() const { return pNum; }
    PrimeNumber operator ++(); //prefix
    PrimeNumber operator ++(int ignoreMe); //postfix
    PrimeNumber operator --();
    PrimeNumber operator --(int ignoreMe);
    bool isPrime(const int& num);
private:
    int pNum;
};

int main( )
{
    int x;
    cout << "enter prime number => ";
    cin >> x;
    
    PrimeNumber p(x);
    PrimeNumber hold = p++;
    cout << "Value of hold => " << hold.getNum() << endl;
    cout << "Value of p => " << p.getNum() << endl;
    
    cout << "enter prime number => ";
    cin >> x;
    
    PrimeNumber p2(x);
    PrimeNumber hold2 = ++p2;
    cout << "Value of hold2 => " << hold2.getNum() << endl;
    cout << "Value of p2 => " << p2.getNum() << endl;
    
    cout << "enter prime number => ";
    cin >> x;
    
    PrimeNumber p3(x);
    PrimeNumber hold3 = p3--;
    cout << "Value of hold3 => " << hold3.getNum() << endl;
    cout << "Value of p3 => " << p3.getNum() << endl;
    
    cout << "enter prime number => ";
    cin >> x;
    
    PrimeNumber p4(x);
    PrimeNumber hold4 = --p4;
    cout << "Value of hold4 => " << hold4.getNum() << endl;
    cout << "Value of p4 => " << p4.getNum() << endl;
    
    
    return 0;
}
bool PrimeNumber::isPrime(const int& num)
{
    if (num < 2)
    {
        return false;
    }
    else if (num == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

PrimeNumber PrimeNumber::operator ++() //prefix
{
    pNum += 1;
    while (!isPrime(pNum))
    {
        pNum++;
    }
    return pNum;
}
PrimeNumber PrimeNumber::operator ++(int ignoreMe) //postfix
{
    int temp = pNum;
    while (!isPrime(++pNum)) {}
    return temp;
}
PrimeNumber PrimeNumber::operator --() //prefix
{
    pNum -= 1;
    while (!isPrime(pNum))
    {
        pNum--;
    }
    return pNum;
}
PrimeNumber PrimeNumber::operator --(int ignoreMe) //postfix
{
    int temp = pNum;
    while (!isPrime(--pNum)) {}
    return temp;
}