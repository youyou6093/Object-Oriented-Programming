#include<iostream>
#include"temperature.h"
#include<string>
#include<iomanip>
using namespace std;


//private function
double Temperature::convert_to_k(double deg,char s){
    //cout<<degrees<<"test"<<endl;
    s=toupper(s);
    switch(s){
        case 'C': return deg+273.15;
        case 'F': return (deg-32.0)*5.0/9.0+273.15;
        case 'K': return deg;
        default: return -1;
    }
}

bool Temperature::isvalid(double deg,char s){
    s=toupper(s);
    return (convert_to_k(deg,s)>=0);
}



string Temperature::transform_to_long(char s){
    switch (s) {
        
        case 'C':
            return "Celsius";
           
        case 'F':
            return "Fahrenheit";
            
        case 'K':
            return "Kelvin";
            
        default:
            break;
    }
    return "wrong";
    
}

char Temperature::format='D';

//public function
Temperature::Temperature(){
    degrees=0.0;
    scale='C';
    degrees_k=convert_to_k(degrees,scale);
}


Temperature::Temperature(double a,char b):degrees(a),scale(b){
    b=toupper(b);
    switch(b){
        case 'C': scale=b;break;
        case 'F': scale=b;break;
        case 'K': scale=b;break;
        default: scale='C';degrees=0;
     }
    degrees_k=convert_to_k(degrees,scale);
    if (degrees_k<0){
        degrees=0;
        scale='C';
        degrees_k=0;
    }// if the value constructed is not vaild
}

bool Temperature::Set(double deg, char s){
    if (isvalid(deg,s)){
        degrees=deg;
        scale=toupper(s);
        degrees_k=convert_to_k(degrees,scale);
        return true;
    }
    else
        return false;
}

bool Temperature::SetFormat(char f){
    f=toupper(f);
    switch(f){
        case 'D': format=f; return 1;
        case 'P': format=f; return 1;
        case 'L': format=f; return 1;
        default: return 0;
    }
}

double Temperature::GetDegrees() const{
    return degrees;
}

char Temperature::GetScale() const{
    return scale;
}

bool Temperature::Convert(char s){
    s=toupper(s);
    switch(s){
        case 'C': degrees=degrees_k-273.15;
                  scale='C';
                  return 1;
        case 'K': degrees=degrees_k;
                  scale='K';
                  return 1;
        case 'F': degrees=1.8*(degrees_k-273.15)+32.0;
                  scale='F';
                  return 1;
        default:  return 0;
    }
}

int Temperature::Compare(const Temperature &d){
    if (d.degrees_k<degrees_k)
        return 1;
    else if(d.degrees_k>degrees_k)
        return -1;
    else
        return 0;
}

void Temperature::Input(){
    double a;
    char b;
    cin>>a;
    cin>>b;
    b=toupper(b);
    while(isvalid(a,b)==0){
        cout<<"Invalid temperature. Try again:\n";
        cin>>a;
        cin>>b;
    }
    degrees=a;
    scale=toupper(b);
    degrees_k=convert_to_k(a,b);
    
}

void Temperature::Show(){
    string full_name;
    full_name=transform_to_long(scale);
    switch(format){
        case 'D': cout<<degrees<<' '<<scale<<endl;
            break;
        case 'P': cout<<fixed<<showpoint<<setprecision(1);
            cout<<degrees<<' '<<scale<<endl;
            break;
        case 'L':
            cout<<degrees<<' '<<full_name<<endl;
            
    }
}


void Temperature::Increment(int deg,char sc){           //actual
    double updates=convert_to_k(deg,sc)-convert_to_k(0,sc);
    degrees_k+=updates;
    Convert(scale);
    
}

