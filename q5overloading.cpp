#include <iostream>
#include <cstdlib>
using namespace std;

class Vector2D
{
public:
    Vector2D() : x(0), y(0) {}
    Vector2D(int valX, int valY) : x(valX), y(valY) {}
    int getX() const;
    int getY() const;
    void setX();
    void setY();
    int operator *(const Vector2D& componentY) const;
private:
    int x;
    int y;
};

int main( )
{
    cout << "Enter 2 integers separated by a space\n" <<
    "to create a new 2D Vector: ";
    
    Vector2D v1;
    v1.setX();
    v1.setY();
    
    cout << "\nVector created!!\n\nEnter a second pair: ";
    
    Vector2D v2;
    v2.setX();
    v2.setY();
    
    cout << "\n\nAnother Vector created!!!\n\n" <<
    "The dot product is " << v1 * v2 << "\n\n";

    
    return 0;
}
int Vector2D::getX() const
{
    return x;
}
int Vector2D::getY() const
{
    return y;
}
void Vector2D::setX()
{
    cin >> x;
}
void Vector2D::setY()
{
    cin >> y;
}
int Vector2D::operator *(const Vector2D& componentY) const
{
    return x * componentY.x + y * componentY.y;
}