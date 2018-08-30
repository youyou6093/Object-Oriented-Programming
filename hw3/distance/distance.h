#include<iostream>
using namespace std;


class Distance{
    friend ostream &operator<<(ostream &os,const Distance &d);
    friend istream &operator>>(istream &is,Distance &d);
    friend bool operator==(const Distance &d1,const Distance &d2);
    friend bool operator<(const Distance &d1,const Distance &d2);
    friend bool operator>(const Distance &d1,const Distance &d2);
    friend bool operator<=(const Distance &d1,const Distance &d2);
    friend bool operator>=(const Distance &d1,const Distance &d2);
    friend bool operator!=(const Distance &d1,const Distance &d2);
    friend Distance operator+(const Distance &d1,const Distance &d2);
    friend Distance operator-(const Distance &d1,const Distance &d2);
    friend Distance operator*(const Distance &d1,int x);
    friend Distance operator*(int x,const Distance &d1);
    int pmiles;
    int pyards;
    int pfeet;
    int pinches;
    void simplify();
    double convert_to_double () const;
    bool check(int,int,int,int);
public:
    Distance();
    Distance(int inches);   //conversion constructor
    Distance(int miles,int yards,int feet,int inches);
    Distance &operator++();  //prefix increment
    Distance operator++(int); //postfix
    Distance &operator--();   //prefix
    Distance operator--(int); //postfix
};
