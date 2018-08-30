#include<iostream>
#include<iomanip>
#include "triangle.h"
#include<cmath>
using namespace std;


Triangle::Triangle(int n,char a,char b){
    size=n;
    if(n<MIN_SIZE) size=MIN_SIZE;
    if(n>MAX_SIZE) size=MAX_SIZE;
    border=a;
    fill=b;
}

int Triangle::GetSize() const{
    return size;
}

int Triangle::Perimeter() const{
    return 3*size;
}

double Triangle::Area() const{
    return sqrt(3.0)/2.0*size*size/2.0;
}

void Triangle::Grow(){
    if(size<MAX_SIZE)
        size+=1;
}

void Triangle::Shrink(){
    if(size>MIN_SIZE)
        size-=1;
}

void Triangle::SetBorder(char a){
    int x=int(a);
    if(x>=33 && x<=126)
        border=a;
    else
        border='#';
}

void Triangle::SetFill(char a){
    int x=int(a);
    if(x>=33 && x<=126)
        fill=a;
    else
        fill='*';
}

void Triangle::Draw() const{
    int border_pos1,border_pos2;
    int k;
    for(int i=0;i<size;i++){
        char a[size*2-1];
        for(int j=0;j<size*2-1;j++) a[j]=' ';
        border_pos1=(size*2-1)/2-i;
        border_pos2=(size*2-1)/2+i;
        a[border_pos1]=border;
        a[border_pos2]=border;
        k=border_pos1;
        while(k<border_pos2-1){
            k++;
            a[k]=' ';
            if((k+1)<border_pos2){
                if (i==(size-1)) a[++k]=border;
                else a[++k]=fill;
            }
        }
        for(int j=0;j<size*2-1;j++) cout<<a[j];
        cout<<endl;}
}


void Triangle::Summary() const{
    cout<<"Size of triangle's side = "<<size<<" units."<<'\n';
    cout<<"Perimeter of triangle = "<<Perimeter()<<" units."<<'\n';
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Area of triangle = "<<Area()<<" units."<<'\n';
    cout<<"Triangle looks like:"<<endl;
    Draw();
}
