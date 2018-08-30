// starter file for MyInt class header
// storage model: i put the integer as a string in myint class, the order is just the same as a normal integer
#include <iostream>
using namespace std;

//int memory=0;

class MyInt
{
    // these overload starters are declared as friend functions
    
    friend MyInt operator+ (const MyInt& x, const MyInt& y);
    // add in multiplication, as well
    friend MyInt operator* (const MyInt& x,const MyInt & y);
    friend bool operator< (const MyInt& x, const MyInt& y);
    friend bool operator<=(const MyInt& x,const MyInt& y);
    friend bool operator==(const MyInt& x,const MyInt& y);
    friend bool operator!=(const MyInt& x,const MyInt& y);
    friend bool operator>=(const MyInt& x,const MyInt& y);
    friend bool operator>(const MyInt& x,const MyInt& y);
    friend ostream &operator<<(ostream &os,const MyInt &y);
    friend istream &operator>>(istream &is,MyInt &y);
    
    // add in the other comparison overloads, as well
    
    // declare overloads for input and output (MUST be non-member functions)
    //  you may make them friends of the class
    
public:
    MyInt(int n=0);		// first constructor
    MyInt(const char* s);
    MyInt(const MyInt&x );   //deep copy
    ~MyInt();
    MyInt &operator=(const MyInt &x);
    MyInt &operator++();          //prefix
    MyInt operator++(int);        //postfix
    // be sure to add in the second constructor, and the user-defined
    //  versions of destructor, copy constructor, and assignment operator
    
private:
    MyInt Digit_multi(int x) const;
    void Grow();   //when do i need this ?
    void Shrink();  //when?
    void Shift(int x);
    bool Check(const char *s);
    void Reverse();
    void Delete_zero();
    // MyInt Multiply(int d);
    char *pInt;      // I store the digit in right order;
    int len;
    int size;
};
