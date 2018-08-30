#include<iostream>
#include"distance.h"
using namespace std;



double Distance::convert_to_double () const{
    return pmiles+pyards/1760.0+pfeet/5280.0+pinches/63360.0;
}

void Distance::simplify(){
    int increase[3];
    int remain[3];
    do{
        increase[0]=pinches/12;
        remain[0]=pinches % 12;
        increase[1]=pfeet/3;
        remain[1]=pfeet%3;
        increase[2]=pyards/1760;
        remain[2]=pyards%1760;
        pyards=remain[2];
        pfeet=remain[1];
        pinches=remain[0];
        pmiles+=increase[2];
        pyards+=increase[1];
        pfeet+=increase[0];
    }while(increase[0]||increase[1]||increase[2]);
}



Distance::Distance(){
    pmiles=0;
    pyards=0;
    pfeet=0;
    pinches=0;
}

bool Distance::check(int a,int b,int c,int d){
    if((a<0)||(b<0)||(c<0)||(d<0)) return 0;
    else return 1;
}


Distance::Distance(int inches){
    if (inches>0){
        pinches=inches;
        pmiles=0;
        pyards=0;
        pfeet=0;
        simplify();
    }
    else{
        pinches=0;
        pmiles=0;
        pyards=0;
        pfeet=0;
    }
}

Distance::Distance(int miles,int yards,int feet,int inches){
    if(check(miles,yards,feet,inches)){
        pmiles=miles;
        pinches=inches;
        pfeet=feet;
        pyards=yards;
        simplify();}
    else{pinches=0;
        pmiles=0;
        pyards=0;
        pfeet=0;}
}



ostream &operator<<(ostream &os,const Distance &d){

    os<<'(';
    if(d.pmiles>0) os<<d.pmiles<<'m'<<' ';
    if(d.pyards>0) os<<d.pyards<<'y'<<' ';
    if(d.pfeet>0)  os<<d.pfeet<<'\''<<' ';
    os<<d.pinches<<'"'<<')';
    return os;
}


istream &operator>>(istream &is,Distance &d){
    char c;
    
    is>>d.pmiles>>c>>d.pyards>>c>>d.pfeet>>c>>d.pinches;
    if((c!=',') || (d.check(d.pmiles,d.pyards,d.pfeet,d.pinches)==0)){
        d.pmiles=0;
        d.pyards=0;
        d.pfeet=0;
        d.pinches=0;
    }
    d.simplify();
    return is;
}

bool operator==(const Distance &d1,const Distance &d2){
    if ((d1.pmiles==d2.pmiles) && (d1.pyards==d2.pyards) && (d1.pfeet==d2.pfeet) && (d1.pinches==d2.pinches))
        return 1;
    else return 0;
}

bool operator<(const Distance &d1,const Distance &d2){
    if(d1.pmiles!=d2.pmiles) return (d1.pmiles<d2.pmiles);
    else if(d1.pyards!=d2.pyards) return (d1.pyards<d2.pyards);
    else if(d1.pfeet!=d2.pfeet) return (d1.pfeet<d2.pfeet);
    else return(d1.pinches<d2.pinches);
}

bool operator>(const Distance &d1,const Distance &d2){
    return (!(d1<d2) && !(d1==d2));
}

bool operator<=(const Distance &d1,const Distance &d2){
    return ((d1<d2) || (d1==d2));
}

bool operator>=(const Distance &d1,const Distance &d2){
    return !(d1<d2);
}


bool operator!=(const Distance &d1,const Distance &d2){
    return !(d1==d2);
}


Distance operator+(const Distance &d1,const Distance &d2){
    int miles,yards,feet,inches;
    miles=d1.pmiles+d2.pmiles;
    yards=d1.pyards+d2.pyards;
    feet=d1.pfeet+d2.pfeet;
    inches=d1.pinches+d2.pinches;
    Distance d3(miles,yards,feet,inches);
    return d3;
}


Distance operator-(const Distance &d1,const Distance &d2){
    int miles,yards,feet,inches;
    miles=d1.pmiles-d2.pmiles;
    yards=d1.pyards-d2.pyards;
    feet=d1.pfeet-d2.pfeet;
    inches=d1.pinches-d2.pinches;
    if (inches<0){
        inches=inches+12;
        feet=feet-1;
    }
    if(feet<0){
        feet=feet+3;
        yards=yards-1;
    }
    if(yards<0){
        yards=yards+1760;
        miles=miles-1;
    }
    Distance d3(miles,yards,feet,inches);
    return d3;
}

Distance operator*(const Distance &d1,int x){
    int miles,yards,feet,inches;
    miles=d1.pmiles*x;
    yards=d1.pyards*x;
    feet=d1.pfeet*x;
    inches=d1.pinches*x;
    Distance d2(miles,yards,feet,inches);
    return d2;
    
}

Distance operator*(int x,const Distance &d1){
    int miles,yards,feet,inches;
    miles=d1.pmiles*x;
    yards=d1.pyards*x;
    feet=d1.pfeet*x;
    inches=d1.pinches*x;
    Distance d2(miles,yards,feet,inches);
    return d2;
}

Distance &Distance::operator++(){
    pinches+=1;
    simplify();
    return *this;
}

Distance Distance::operator++(int){
    Distance copy=*this;
    pinches+=1;
    simplify();
    return copy;
    
    
}

Distance &Distance::operator--(){
    Distance d1(pmiles,pyards,pfeet,pinches);
    Distance d2(1);
    Distance d3=d1-d2;
    pmiles=d3.pmiles;
    pyards=d3.pyards;
    pfeet=d3.pfeet;
    pinches=d3.pinches;
    return *this;
}

Distance Distance::operator--(int){
    Distance copy=*this;
    Distance d1(pmiles,pyards,pfeet,pinches);
    Distance d2(1);
    Distance d3=d1-d2;
    pmiles=d3.pmiles;
    pyards=d3.pyards;
    pfeet=d3.pfeet;
    pinches=d3.pinches;
    return copy;
    
}


