
#include <iostream>
#include <cstring>
#include "myint.h"

using namespace std;


int max(int a,int b){
    if(a>=b)
        return a;
    else
        return b;
}

int C2I(char c)
// converts character into integer (returns -1 for error)
{
    if (c < '0' || c > '9')	return -1;	// error
    return (c - '0');				// success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
    if (x < 0 || x > 9)		return '\0';	// error
    return (static_cast<char>(x) + '0'); 	// success
}

// Add in operator overload and member function definitions


void MyInt::Grow(){          //grow the function when needed
    int newsize=size+5;
    char *copy=new char[newsize+1];
    if(pInt){
        for(int i=0;i<len;i++)  copy[i]=pInt[i];
        delete []pInt;
        size=newsize;
        pInt=copy;
    }
    else{
        copy[0]=0;
        len=1;
        size=newsize;
        pInt=copy;
    }
    //cout<<"grew,new int"<<"length="<<len<<"size="<<size<<endl;
    
}


void MyInt::Reverse(){                 //not sure good or not
    
    char c[len+1];
    for(int i=0;i<len;i++)
        c[i]=pInt[len-i-1];
    for(int i=0;i<len;i++)
        pInt[i]=c[i];
}


bool MyInt::Check(const char* s){      //check whether the string is valid
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(int(s[i])<48||int(s[i])>57)
            return 0;
    }
    return 1;
}


void MyInt::Delete_zero(){              //DELETE ZEROS IN MYINT OBJECT
    char c;
    if(len==1)
        return;
    else{
        Reverse();
        c=pInt[len-1];
        while(c=='0'){
            len--;
            c=pInt[len-1];
            if (len==1)
                break;
        }
        char *copy=new char[len+1];
        for(int i=0;i<len;i++){
            copy[i]=pInt[i];
        }
        //copy[n]='\0';
        delete []pInt;
        pInt=copy;
        size=len;
        Reverse();
    }
}






//****************************************************************comprasion part
bool operator< (const MyInt& x, const MyInt& y){
    bool small=1;
    if(x.len<y.len){
        return 1;
    }else if(x.len>y.len){
        return 0;
    }
    else{
        int i=0;
        do{
            if(C2I(x.pInt[i])<C2I(y.pInt[i])) return 1;
            if(C2I(x.pInt[i])>C2I(y.pInt[i])) return 0;
            i++;
        }while( i<x.len);
    }
    return 0;
}

bool operator<=(const MyInt& x,const MyInt& y){
    return ((x<y) || (x==y));
}

bool operator==(const MyInt& x,const MyInt& y){
    if(x.len!=y.len)
        return 0;
    for(int i=0;i<x.len;i++)
        
        if(x.pInt[i]!=y.pInt[i])
            return 0;
    return 1;
}

bool operator!=(const MyInt& x,const MyInt& y){
    return !(x==y);
}

bool operator>=(const MyInt& x,const MyInt& y){
    return !(x<y);
}

bool operator>(const MyInt& x,const MyInt& y){
    return !(x<=y);
}

//**********************************************************************



ostream &operator<<(ostream &os,const MyInt &y){           //output
    //os<<y.pInt<<' '<<y.size<<' '<<strlen(y.pInt);
    //if (y.len==0){
    //    os<<"nothing"<<endl;
    //    return os;
    //}
    for(int i=0;i<y.len;i++)
        os<<y.pInt[i];
    //os<<" length="<<y.len<<' '<<"size="<<y.size;
    return os;
}


istream &operator>>(istream &is,MyInt &y){                //input
    if(y.pInt){
        delete []y.pInt;
        y.pInt=NULL;
        y.size=0;
        y.len=0;
    }
    char a;
    int k=0;
    do{
        a=cin.peek();
        //a=getchar();
        if(int(a)>=48 && int(a)<=57){
            cin.get(a);
            y.len++;
            if(y.len>y.size) y.Grow();
            y.pInt[k]=a;
            k++;
            //cout<<a<<endl;
            //cout<<"condition1"<<endl;
        }
        else if((a==' ')||(a=='\n')){
            cin.get(a);
            //cout<<a<<endl;
            //cout<<"condition2"<<a<<endl;
            break;
        }
        else{
            //a=getchar();
            //cout<<"condition3"<<endl;
            //cout<<a<<endl;
            break;
        }
    }while(1);
    y.len=k;
    if(!(y>=0)){
        y=0;
    }
    y.Delete_zero();
    return is;
}



MyInt operator+ (const MyInt& x, const MyInt& y){ //addtion overload
    int a,b,c,increase,remain;
    MyInt z;
    delete []z.pInt;
    z.pInt=NULL;
    z.size=0;
    z.len=0;
    int k=0,i=x.len-1,j=y.len-1;       //need to think about it
    //cout<<i<<' '<<j<<endl;
    //k is the current digits of z,note the order of digits in z is reversed now
    while(i>=0||j>=0){
        
        if (z.len>0)    c=C2I(z.pInt[k]);           //current digits of z
        else c=0;
        //cout<<c<<endl;
        z.len++;
        //cout<<z.len<<' '<<i<<' '<<j<<' '<<k<<endl;
        if(z.len>z.size) {
            //cout<<1<<endl;
            z.Grow();
        }
        //cout<<1<<endl;
        if(i>=0) a=C2I(x.pInt[i]); //current digits of x
        else a=0;
        if(j>=0) b=C2I(y.pInt[j]); //current digits of y
        else b=0;
        remain=(a+b+c)%10;
        increase=(a+b+c)/10;
        c=remain;
        z.pInt[k]=I2C(c);             //current digits of z is now remain
        k++;
        z.pInt[k]=I2C(increase);      //next digits of z is now increase
        i--;
        j--;
    }
    z.len++;
    //cout<<k<<' '<<z.len<<endl;
    //cout<<z.len<<' '<<k<<' '<<z.pInt[k]<<endl;
    //cout<<z<<endl;
    //z.pInt[++k]='\0';                //add the end sign for the z object
    z.Reverse();                        //don't forget to reverse
    z.Delete_zero();                    //delete the zeros before z
    return z;
}


MyInt operator* (const MyInt& x,const MyInt & y){
    //int n=strlen(y.pInt);
    //cout<<n<<endl;
    int i=y.len-1;
    int current;
    int shift;
    MyInt z;
    MyInt add;
    while(i>=0){
        current=C2I(y.pInt[i]);
        add=x.Digit_multi(current);
        
        //cout<<current<<' '<<i<<' '<<add<<endl;
        
        shift=y.len-1-i;
        add.Shift(shift);
        //cout<<"current="<<current<<' '<<"after multi="<<add<<endl;
        //cout<<z<<endl;
        //cout<<add<<endl;
        z=z+add;
        //cout<<z<<endl;
        
        
        i--;
    }
    return z;
}

MyInt MyInt::Digit_multi(int x) const{
    MyInt y;
    delete []y.pInt;
    y.pInt=NULL;
    y.size=0;
    y.len=0;
    int i=len-1,k=0;      //i is the current digit for pint, k is the current digit for new object
    int current_x,current_y,increase,remain;
    while(i>=0){
        if (y.len>0)    current_y=C2I(y.pInt[k]);           //current digits of z
        else current_y=0;
        y.len++;
        if(y.len>y.size) y.Grow();
        //cout<<y<<endl;
        // break;
        current_x=C2I(pInt[i]);
        //current_y=C2I(y.pInt[k]);
        //cout<<current_x<<' '<<current_y<<endl;
        
        remain=(current_x*x+current_y)%10;
        increase=(current_x*x+current_y)/10;
        //cout<<current_x<<' '<<current_y<<' '<<remain<<' '<<increase<<endl;
        y.pInt[k]=I2C(remain);
        k++;
        
        y.pInt[k]=I2C(increase);
        i--;
    }
    y.len++;
    //y.pInt[++k]='\0';
    //cout<<y.len<<' '<<k<<endl;
    y.Reverse();
    y.Delete_zero();
    return y;
}

void MyInt::Shift(int n){
    int newsize=n+len;
    int i=0;
    char *copy=new char[newsize+1];
    for(i=0;i<newsize;i++){
        //cout<<i<<endl;
        if (i<len)
            copy[i]=pInt[i];
        else
            copy[i]=I2C(0);
        //cout<<copy[i]<<' '<<i<<endl;
    }
    //copy[i]='\0';
    //cout<<copy<<endl;
    delete []pInt;
    pInt=copy;
    len=len+n;
    size=newsize;
    
    
    //cout<<copy<<endl;
}




MyInt::~MyInt(){                                //desturctor
    delete []pInt;
    pInt=NULL;
    len=0;
    size=0;
}


MyInt::MyInt(int n){                    //CONSTRUCTOR FROM INTEGER
    if (n<=0){
        size=1;
        len=1;
        pInt=new char[size+1];
        pInt[0]='0';
    }
    else{
        char c[100];
        int remain=n;
        int digit=0;
        int i=0;
        while(remain){
            digit=remain%10;
            remain=remain/10;
            c[i]=I2C(digit);
            i++;
        }
        size=i;
        len=i;
        pInt=new char[size+1];
        for(int i=0;i<len;i++){
            pInt[i]=c[i];
        }
        //pInt[size]='\0';     //this part is very important
        Reverse();           // make the string to the right order;
    }
}


MyInt::MyInt(const char*s){                //CONSTRUCTOR FROM STRING
    if (Check(s)==0){
        size=1;
        len=1;
        pInt=new char[size+1];
        pInt[0]='0';
    }
    else{
        size=strlen(s);
        len=size;
        pInt=new char[size+1];
        for(int i=0;i<len;i++)
            pInt[i]=s[i];
    }
    Delete_zero();                  //delete zeros;
}




MyInt::MyInt(const MyInt &x){         //COPY CONSTRUCTOR
    size=x.size;
    len=x.len;
    pInt=new char[size+1];
    for(int i=0;i<len;i++) pInt[i]=x.pInt[i];
}



MyInt& MyInt::operator=(const MyInt &x){                    //ASSIGNMENT CONSTURCTOR
    if (pInt){
        delete []pInt;
        pInt=NULL;
        size=0;
        len=0;
    }
    size=x.size;
    len=x.len;
    pInt=new char[size+1];
    for(int i=0;i<len;i++)
        pInt[i]=x.pInt[i];
    return *this;
}


MyInt& MyInt::operator++(){
    *this=*this+1;
    return *this;
    
}

MyInt MyInt::operator++(int){
    MyInt copy=*this;
    *this=*this+1;
    return copy;
}

















