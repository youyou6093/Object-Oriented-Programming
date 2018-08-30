#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;


class Triangle{
    
    int size;
    char border;
    char fill;
    
public:
    Triangle();
    Triangle(int n,char a='#',char b='*');
    int GetSize();
    int Perimeter();
    double Area();
    void Grow();
    void Shrink();
    void Draw();
    void Summary();
    void SetBorder(char a);
    void SetFill(char a);
};


Triangle::Triangle(){
    size=1;
    border='#';
    fill='*';
}

Triangle::Triangle(int n,char a,char b){
    size=n;
    if(n<1) size=1;
    if(n>39) size=39;
    border=a;
    fill=b;
}

int Triangle::GetSize(){
    return size;
}

int Triangle::Perimeter(){
    return 3*size;
}

double Triangle::Area(){
    return sqrt(3.0)/2.0*size*size/2.0;
}

void Triangle::Grow(){
    if(size<39)
        size+=1;
}

void Triangle::Shrink(){
    if(size>1)
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

void Triangle::Draw(){
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

void Triangle::Summary(){
    cout<<"Size of triangle's side = "<<size<<" units."<<'\n';
    cout<<"Perimeter of triangle = "<<Perimeter()<<" units."<<'\n';
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Area of triangle = "<<Area()<<" units."<<'\n';
    cout<<"Triangle looks like:"<<endl;
    Draw();
}


int main()
{
    // create some Triangles
    Triangle t1( -5 ), t2( 7, '^' ), t3( 12, 'X', 'O' ), t4( 50 , '$' , 'o');
    // display original Triangles
    
    cout << "t1 has size = " << t1.GetSize() << " units.\n";
    t1.Draw();
    cout << "\nt2 has size = " << t2.GetSize() << " units.\n";
    t2.Draw();
    cout << "\nt3 has size = " << t3.GetSize() << " units.\n";
    t3.Draw();
    cout << "\nt4 has size = " << t4.GetSize() << " units.\n";
    t4.Draw();
    cout << '\n';
    
    t1.Shrink(); // demonstrate shrink
    t2.Shrink();
    t3.Grow(); // and grow
    t4.Grow();
    cout << "t1 now has size = " << t1.GetSize() << " units.\n";
    cout << "t2 now has size = " << t2.GetSize() << " units.\n";
    cout << "t3 now has size = " << t3.GetSize() << " units.\n";
    cout << "t4 now has size = " << t4.GetSize() << " units.\n";
    
    // demonstrate perimeter
    cout << "t2 has perimeter = " << t2.Perimeter() << " units.\n";
    cout << "t3 has perimeter = " << t3.Perimeter() << " units.\n";
    // and area
    cout << "t2 has area = " << t2.Area() << " square units.\n\n";
    cout << "t3 has area = " << t3.Area() << " square units.\n\n";
    
    t1.Draw();
    t1.Grow();               // show that fill character
    cout << "t1 grows:\n";   // appears only when size
    t1.Draw();               // is at least 3
    t1.Grow();
    cout << "... and grows:\n";
    t1.Draw();
    cout << '\n';
    
    t1 = t2; // demonstrate the default overload of the
    // assignment operator
    cout << "t1 now has size = " << t1.GetSize() << " units.\n";
    t1.Draw();
    
    // demonstrate the changing of border and fill characters
    t2.SetBorder('@');
    t2.SetFill('-');
    cout << "t2 now looks like:\n";
    t2.Draw();
    cout << '\n';
    t2.SetBorder('\n');	 // illegal border
    t2.SetFill('\a');	 // illegal fill
    cout << "t2 now looks like:\n";
    t2.Draw();
    cout << '\n';
    
    cout << "\nHere is a summary on t3:\n"; // demonstrate summary
    t3.Summary();
    
    return 0;
}
