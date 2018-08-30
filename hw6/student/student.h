#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class Student{
public :
    virtual void Set(string a,string b,string c);
    virtual ofstream& Output(ofstream& os)=0;
    Student();
    Student(string a,string b,string c);
    string Get_name();
    virtual ~Student();
        //virtual phrse
    virtual double Average()=0;
protected:
    
    //first name ,last name ,course
    string name1;
    string name2;
    string course;
};

class English : public Student{
    
public:
    ofstream& Output(ofstream& os);
    double Average();
    void Set(int arr[],string a,string b,string c);
    English();
    English(int arr[],string a,string b,string c);
    //~English();
private:
    int attendance;
    int project;
    int mid;
    int finalexam;
    // need some states to store input numbers
};

class History :public Student{
    
    
public:
    ofstream& Output(ofstream& os);
    double Average();
    
    History(int arr[],string a,string b,string c);
    History();
    //~History();
    void Set(int arr[],string a,string b,string c);
private:
    int term;
    int mid;
    int finalexam;
    //compute average
};


class Math :public Student{

public:
    ofstream& Output(ofstream& os);

    double Average();
    //~Math();
    Math(int arr[],string a,string b,string c);
    Math();
    void Set(int arr[],string a,string b,string c);
    
private:
    int q1,q2,q3,q4,q5,t1,t2,finalexam;
    //compute average
};

#endif
