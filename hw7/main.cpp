#include <iostream>
#include "stack.h"
#include <cstring>
#include <cctype>
using namespace std;

int main(){
    
    
    //List<int> h;
    //h.insertAtBack(1);
    //h.insertAtBack(2);
    //h.insertAtBack(3);
    //h.insertAtBack(4);
    //h.print();
    //int x;
    //h.insertMiddle(100,5);    //cout<<x<<endl;
    //h.print();
    Stack<char> my_stack;
    char a,b;
    char my_str[100];
    char newstr[100];
    cout<<"Please enter a string:"<<endl;
    cin.getline(my_str,100);
    int n=strlen(my_str);
    int num=0;
    for(int i=0;i<n;i++){
        
        while(isalpha(my_str[i])==0) i++;
        if(i<n){
            //cout<<my_str[i]<<' '<<i<<endl;
            newstr[num]=my_str[i];
            my_stack.push(my_str[i]);
            num++;
        }
    }
    bool flag=1;
    //cout<<num<<endl;
    //cout<<
    for(int i=0;i<num;i++){
        my_stack.pop(a);
        //cout<<a<<' '<<newstr[i]<<endl;
        if(toupper(a)!=toupper(newstr[i])){
            
            flag=0;
            //break;
        }
    }
    //cout<<newstr<<endl;
    //my_stack.printStack();
    if(flag==1)
        cout<<'\"'<<my_str<<'\"'<<"IS a palindrome"<<endl;
    
    else
        cout<<'\"'<<my_str<<'\"'<<"is NOT a palindrome"<<endl;
}


