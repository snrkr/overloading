#include <iostream>
using namespace std;

class Rational
{
public:
    Rational(int setNum, int setDenom) : numerator(setNum), denominator(setDenom) {}
    Rational(int wholeNumber) : numerator(wholeNumber), denominator(1) {}
    Rational() : numerator(0), denominator(1) {}
    friend istream& operator >>(istream& inputStream, Rational& val);
    friend ostream& operator <<(ostream& outputStream, const Rational& val);
    const bool operator ==(const Rational& val) const;
    const bool operator <(const Rational& val) const;
    const bool operator <=(const Rational& val) const;
    const bool operator >(const Rational& val) const;
    const bool operator >=(const Rational& val) const;
    friend const Rational operator +(const Rational& val1, const Rational& val2);
    friend const Rational operator -(const Rational& val1, const Rational& val2);
    friend const Rational operator *(const Rational& val1, const Rational& val2);
    friend const Rational operator /(const Rational& val1, const Rational& val2);
private:
    int numerator;
    int denominator;
};


int main()
{
    Rational fraction1(2,5);
    Rational fraction2;
    
    cin >> fraction2;
    
    cout << ( fraction1 == fraction2 ) << endl;
    cout << ( fraction1 < fraction2 ) << endl;
    cout << ( fraction1 <= fraction2 ) << endl;
    cout << ( fraction1 > fraction2 ) << endl;
    cout << ( fraction1 >= fraction2 ) << endl;
    
    cout << ( fraction1 + fraction2 ) << endl;
    cout << ( fraction1 - fraction2 ) << endl;
    cout << ( fraction1 * fraction2 ) << endl;
    cout << ( fraction1 / fraction2 ) << endl;
    
    return 0;
}

istream& operator >>(istream& inputStream, Rational& val)
{
    //char minusSign;
    char fractionSign;
    inputStream >> val.numerator;
    inputStream >> fractionSign;
    inputStream >> val.denominator;
    return inputStream;
}
ostream& operator <<(ostream& outputStream, const Rational& val)
{
    outputStream << val.numerator << "/" << val.denominator;
    return outputStream;
}

const bool Rational::operator ==(const Rational& val) const
{
    return ( numerator * val.denominator == denominator * val.numerator );
}
const bool Rational::operator <(const Rational& val) const
{
    double holdNum = static_cast<double>(numerator);
    double holdValNum = static_cast<double>(val.numerator);
    return ( holdNum / denominator ) < ( holdValNum / val.denominator );
}
const bool Rational::operator <=(const Rational& val) const
{
    double holdNum = static_cast<double>(numerator);
    double holdValNum = static_cast<double>(val.numerator);
    return ( holdNum / denominator ) <= ( holdValNum / val.denominator );
}
const bool Rational::operator >(const Rational& val) const
{
    double holdNum = static_cast<double>(numerator);
    double holdValNum = static_cast<double>(val.numerator);
    return ( holdNum / denominator ) > ( holdValNum / val.denominator );
}
const bool Rational::operator >=(const Rational& val) const
{
    double holdNum = static_cast<double>(numerator);
    double holdValNum = static_cast<double>(val.numerator);
    return ( holdNum / denominator ) >= ( holdValNum / val.denominator );
}
const Rational operator +(const Rational& val1, const Rational& val2)
{
    int sumNum = ( val1.numerator * val2.denominator ) + ( val2.numerator * val1.denominator );
    int sumDenom = val1.denominator * val2.denominator;
    return Rational(sumNum,sumDenom);
}
const Rational operator -(const Rational& val1, const Rational& val2)
{
    int diffNum = ( val1.numerator * val2.denominator ) - ( val2.numerator * val1.denominator );
    int sumDenom = val1.denominator * val2.denominator;
    return Rational(diffNum,sumDenom);
}
const Rational operator *(const Rational& val1, const Rational& val2)
{
    int timesNum = val1.numerator * val2.numerator;
    int timesDen = val1.denominator * val2.denominator;
    return Rational(timesNum,timesDen);
}
const Rational operator /(const Rational& val1, const Rational& val2)
{
    int divNum = val1.numerator * val2.denominator;
    int divDen = val1.denominator * val2.numerator;
    return Rational(divNum,divDen);
}
