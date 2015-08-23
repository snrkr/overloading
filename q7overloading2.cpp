#include <iostream>
#include <cassert>
using namespace std;

class PrimeNumber
{
public:
    PrimeNumber() : pNum(1) {}
    PrimeNumber(int setNum) : pNum(setNum) {}
    int getNum() const { return pNum; }
    PrimeNumber& operator ++(); //prefix
    PrimeNumber operator ++(int ignoreMe); //postfix
    PrimeNumber& operator --();
    PrimeNumber operator --(int ignoreMe);
    bool isPrime(const int& num);
private:
    int pNum;
};

int main( )
{
    auto x = PrimeNumber(2767);
    auto hold = x++;
    assert(hold.getNum() == 2767);
    assert(x.getNum() == 2777);
    
    x = PrimeNumber(123007);
    hold = x--;
    assert(hold.getNum() == 123007);
    assert(x.getNum() == 123001);
    
    x = PrimeNumber(23);
    hold = ++x;
    assert(hold.getNum() == 29);
    assert(x.getNum() == 29);
    
    x = PrimeNumber(19);
    hold = --x;
    assert(hold.getNum() == 17);
    assert(x.getNum() == 17);
    
    cout << "Success!\n";

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

PrimeNumber& PrimeNumber::operator ++() //prefix
{
    pNum += 1;
    while (!isPrime(pNum))
        pNum++;
    return *this;
}

PrimeNumber PrimeNumber::operator ++(int ignoreMe) //postfix
{
    auto copy = *this;
    ++(*this);
    return copy;
}

PrimeNumber& PrimeNumber::operator --() //prefix
{
    pNum -= 1;
    while (!isPrime(pNum))
        pNum--;
    return *this;
}

PrimeNumber PrimeNumber::operator --(int ignoreMe) //postfix
{
    auto copy = *this;
    --(*this);
    return copy;
}