#include<iostream>
using namespace std;

class Temperature{
    double degrees;
    char scale;
    double degrees_k;                   //it is always in kelvin
    static char format;
    bool isvalid(double deg,char s);   //check whether the input of function Set is valid
    double convert_to_k(double deg,char s);  //change any degrees to Kevlin
    string transform_to_long(char s);        //transform scale to its full name
    
public:
    Temperature();
    Temperature(double a,char b);
    double GetDegrees() const;
    char GetScale() const;
    bool Set(double deg, char s);
    bool SetFormat(char f);
    bool Convert(char s);
    int Compare(const Temperature &d);
    void Input();
    void Show();
    void Increment(int deg,char sc); 
    
};


