#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


char Decide_grade(double s){
    if(s>=90)
        return 'A';
    else if(s>=80)
        return 'B';
    else if(s>=70)
        return 'C';
    else if(s>=60)
        return 'D';
    else
        return 'F';
}

string Student::Get_name(){
    //cout<<course<<endl;
    return course;
}

void Student::Set(string a,string b,string c){
    name1=a;
    name2=b;
    course=c;
}

Student::Student(){
    name1="";
    name2="";
    course="";
}

Student::~Student(){}

Student::Student(string a,string b,string c){
    name1=a;
    name2=b;
    course=c;
}



English::English(){
    attendance=0;
    project=0;
    mid=0;
    finalexam=0;
}




English::English(int arr[],string a,string b,string c):Student(a,b,c){
    attendance=arr[0];
    project=arr[1];
    mid=arr[2];
    finalexam=arr[3];
}

void English::Set(int arr[],string a, string b,string c){
    attendance=arr[0];
    project=arr[1];
    mid=arr[2];
    finalexam=arr[3];
    Student::Set( a, b, c);

}


ofstream& History::Output(ofstream& os){
    os<<setw(36);
    os<<left<<name2+" "+name1;
    os<<setw(8);
    os<<left<<finalexam;
    os<<setw(8);
    os<<fixed<<showpoint<<setprecision(2);
    os<<left<<Average();
    os<<setw(8);
    os<<Decide_grade(Average());
    os<<endl;
    return os;
}

ofstream& Math::Output(ofstream& os){
    os<<setw(36);
    os<<left<<name2+" "+name1;
    os<<setw(8);
    os<<left<<finalexam;
    os<<setw(8);
    os<<fixed<<showpoint<<setprecision(2);
    os<<left<<Average();
    os<<setw(8);
    os<<Decide_grade(Average());
    os<<endl;
    return os;
}

ofstream& English::Output(ofstream& os){
    os<<setw(36);
    os<<left<<name2+" "+name1;
    os<<setw(8);
    os<<left<<finalexam;
    os<<setw(8);
    os<<fixed<<showpoint<<setprecision(2);
    os<<left<<Average();
    os<<setw(8);
    os<<Decide_grade(Average());
    os<<endl;
    return os;
}






History::History(){
    term=0;
    mid=0;
    finalexam=0;
}

History::History(int arr[],string a,string b,string c):Student(a,b,c){
    term=arr[0];
    mid=arr[1];
    finalexam=arr[2];
}

void History::Set(int arr[],string a,string b,string c){
    term=arr[0];
    mid=arr[1];
    finalexam=arr[2];
    Student::Set( a, b, c);
}

Math::Math(){
    q1=0;
    q2=0;
    q3=0;
    q4=0;
    q5=0;
    t1=0;
    t2=0;
    finalexam=0;
}

Math::Math(int arr[],string a,string b,string c):Student(a,b,c){
    q1=arr[0];
    q2=arr[1];
    q3=arr[2];
    q4=arr[3];
    q5=arr[4];
    t1=arr[5];
    t2=arr[6];
    finalexam=arr[7];
}

void Math::Set(int arr[],string a,string b,string c){
    q1=arr[0];
    q2=arr[1];
    q3=arr[2];
    q4=arr[3];
    q5=arr[4];
    t1=arr[5];
    t2=arr[6];
    finalexam=arr[7];
    Student::Set( a, b, c);
}


double History::Average(){
    double sum=term*0.25+mid* 0.35+finalexam*0.4;
    //cout<<sum<<endl;
    return (sum);

}


double English::Average(){
    double sum=attendance*0.1+0.3*project+0.3*mid+0.3*finalexam;
    return (sum);

    
}

double Math::Average(){
    //cout<<"math ave"<<endl;
    double ave1=(q1+q2+q3+q4+q5)/5.0;
    double sum=0.15*ave1+0.25*t1+0.25*t2+finalexam*0.35;
    return (sum);
}
