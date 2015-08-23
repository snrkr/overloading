#include <iostream>
#include <cstdlib>
using namespace std;


class CharPair
{
public:
    CharPair( );
    CharPair(int sz);
    CharPair(char takearr[], int sz);
    char& operator[](int index);
    int getSize() const;
private:
    char arr[100];
    char size;
};

int main( )
{
    char testarr[20] = "AAAAAAAAAAAAAAAAAAA";
    CharPair a ;
    CharPair b ( 12 ) ;
    CharPair c ( testarr, 10 ) ;
    //test data
    a [ 1 ] = 'A' ;
    a [ 2 ] = 'B' ;
    cout << a [ 1 ] << endl ;
    cout << a [ 2 ] << endl ;
    for ( int i = 0 ; i < 12 ; i++ )
        cout << b [ i ];
    cout << endl;
    for ( int i = 0 ; i < 10 ; i++ )
        cout << testarr [ i ];
    
    return 0;
}
char& CharPair::operator[](int index)
{
    if (index >= size){
        cout << "Outta boundry" << endl;
        exit(1);
    }
    return arr[index];
}

CharPair::CharPair( ) : size(10)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = '#';
    }
}

CharPair::CharPair(int sz) : size(sz)
{
    if (sz >= 100){
        cout << "Outta boundry" << endl;
        exit(1);
    }
    
    for (int i = 0; i < sz; i++)
    {
        arr[i] = '#';
    }
}
CharPair::CharPair(char takearr[], int sz) : size(sz)
{
    if (sz >= 100){
        cout << "Outta boundry" << endl;
        exit(1);
    }
    
    for (int i = 0; i < sz; i++)
    {
         arr[i] = takearr[i];
    }
}
int CharPair::getSize() const
{
    return size;
}
