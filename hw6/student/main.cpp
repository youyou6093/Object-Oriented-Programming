#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include "student.h"
using namespace std;




int Atoi( const char *c ) {
    int value = 0;
    int sign = 1;
    if( *c == '+' || *c == '-' ) {
        if( *c == '-' ) sign = -1;
        c++;
    }
    while ( isdigit( *c ) ) {
        value *= 10;
        value += (int) (*c-'0');
        c++;
    }
    return value * sign;
}


char decide_grade(double s){
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


void getname(string line,string &a,string &b){
    int n=line.length();
    int pos;
    for(int i=0;i<n;i++){
        if(line[i]==',')
            pos=i;
    }
    a=line.substr(0,pos);
    b=line.substr(pos+2,n-pos);

    
}

void getscores(string line,string &course,int scores[]){
    int n=line.length();
    int n2,k=0;
    int pos1=0,pos2=0;
    bool find=0;
    string left;
    for(int i=0;i<n;i++){
        if(line[i]==' '){
            pos1=i;
            break;}
    }
    course=line.substr(0,pos1);
    left=line.substr(pos1,n-pos1);
    n2=left.length();
    pos1=0;
    for(int i=0;i<n2;i++){
        if(left[i]==' '){
            pos1=i;
            for(int j=pos1+1;j<n2;j++){
                if(left[j]==' ') {
                    find=1;
                    pos2=j;
                }
            }
            if(find==0)
                pos2=n2+1;
            //b = atoi(a.c_str());
            scores[k]=Atoi(left.substr(pos1+1,pos2-pos1-1).c_str());
            k++;
        }
    }
}

ofstream& print_title(ofstream & of,string name){
    of<<setw(36);
    of<<left<<name<<endl;
    of<<endl;
    of<<setw(36);
    of<<left<<"Student";
    of<<setw(8);
    of<<left<<"Final";
    of<<setw(8);
    of<<left<<"Final";
    of<<setw(8);
    of<<left<<"Letter"<<endl;
    of<<setw(36);
    of<<left<<"Name";
    of<<setw(8);
    of<<left<<"Exam";
    of<<setw(8);
    of<<left<<"Avg";
    of<<setw(8);
    of<<left<<"Grade"<<endl;
    string a="----------";
    of<<a+a+a+a+a+a<<endl;
    return of;
    
}

ofstream& print_grade(ofstream &of,char c,int num){
    of<<setw(8);
    of<<c;
    of<<num<<endl;
    return of;
}






int main(){
    cout<<"please enter the input file names and output file names"<<endl;
    string input,output;
    int n;
    string line1,line2,line;
    string firstname,lastname,course;
    int scores[8];
    cin>>input>>output;
    ifstream infile(input.c_str());
    ofstream of(output.c_str());
    of<<"Student Grade Summary"<<endl;
    of<<"---------------------"<<endl;
    of<<endl;
    infile>>n;
    infile.ignore();
    Student ** something = new Student *[n];
    int i=0,j=0,k=0,l=0;
    while(getline(infile,line1)){
        getname(line1,firstname,lastname);
        getline(infile,line2);
        getscores(line2,course,scores);
        switch (course[0]) {
            case 'M':
                something[i]=new Math(scores,firstname,lastname,course);
                //cout<<something[i]->Average()
                j++;
                i++;
                
                break;
            case 'H':
                
                something[i]=new History(scores,firstname,lastname,course);
                
                i++;
                k++;
                break;
            case 'E':
                
                something[i]=new English(scores,firstname,lastname,course);
                i++;
                l++;
                break;
        }
    }
    
    
    if(l>0){
        print_title(of,"English Class");
        for(int i=0;i<n;i++){
            //cout<<(something[i]->Get_name())[0]<<endl;
            if ((something[i]->Get_name())[0]=='E')
                something[i]->Output(of);
        }
        of<<endl;
        of<<endl;
    }
    
    
    if(k>0){
        print_title(of,"History Class");
        for(int i=0;i<n;i++)
            if ((something[i]->Get_name())[0]=='H')
                something[i]->Output(of);
        of<<endl;
        of<<endl;
    }
    if(j>0){
        print_title(of,"Math Class");
        for(int i=0;i<n;i++)
            if ((something[i]->Get_name())[0]=='M')
                something[i]->Output(of);
        of<<endl;
        of<<endl;
    }
    
    
    of<<"OVERALL GRADE DISTRIBUTION"<<endl;
    of<<endl;
    int A=0,B=0,C=0,D=0,F=0;
    for(int i=0;i<n;i++){
        switch (decide_grade(something[i]->Average())) {
            case 'A':
                A++;
                break;
             
            case 'B':
                B++;
                break;
            
            case 'C':
                C++;
                break;
            
            case 'D':
                D++;
                break;
                
            case 'F':
                F++;
                break;
                
            default:
                break;
        }
    }
    
    print_grade(of,'A',A);
    print_grade(of,'B',B);
    print_grade(of,'C',C);
    print_grade(of,'D',D);
    print_grade(of,'F',F);
    
    
    of.close();
    
    for(int i=0;i<n;i++){
        delete something[i];
    }
    delete []something;

    return 0;
}








