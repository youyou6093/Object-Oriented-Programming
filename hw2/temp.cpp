#include<iostream>
using namespace std;

class Temperature{
    double degrees;
    char scale;
    //static const double MIN_KEVIN=0.0;
    bool isvalid(double deg,char s);   //check whether the input of function Set is valid
    double convert_to_k(double deg,char s);
    
public:
    Temperature(int a=0,char b='c');
    double GetDegrees() const;
    char GetScale() const;
    bool Set(double deg, char s);
    bool SetFormat(char f);
    double Convert();
    int Compare(const Temperature &d);
    void Input();
    void Show() const;
    
};


//private function
double Temperature::convert_to_k(double deg,char s){
    switch(s){
        case 'C': return deg+273.15;
        case 'F': return (deg-32.0)*5.0/9.0+273.15;
        case 'K': return deg;
        default: return 0;
    }
}

bool Temperature::isvalid(double deg,char s){
    s=toupper(s);
    return (convert_to_k(deg,s)>0);
}

//public function
Temperature::Temperature(int a,char b):degrees(a),scale(b){
    b=toupper(b);
    switch(b){
        case 'C': scale=b;break;
        case 'F': scale=b;break;
        case 'K': scale=b;break;
        default: scale='C';
     }
}

bool Temperature::Set(double deg, char s){
    if (isvalid(deg,s)){
        degrees=deg;
        scale=toupper(s);
        return true;
    }
    else
        return false;
}

double Temperature::GetDegrees() const{
    return degrees;
}

char Temperature::GetScale() const{
    return scale;
}

double Temperature::Convert(){
    return convert_to_k(degrees,scale);
}



int main(){
    Temperature t1(100,'c');
    cout<<t1.Set(900,'f')<<endl;
    cout<<t1.GetDegrees()<<endl;
    cout<<t1.GetScale()<<endl;
    cout<<t1.Convert()<<endl;
}






//Temptature::Temptature(int a,char b):degrees(a),scale(b){
//  switch (b) {
//     case 'c':   scale='C'; break;
//   case 'C':   scale='C'; break;
//  case 'F':   scale='F'; break;
//  case 'f':   scale='F'; break;
//  case 'k':   scale='K'; break;
//  case 'K':   scale='K'; break;
//  default:    scale='C';
//}
//}
