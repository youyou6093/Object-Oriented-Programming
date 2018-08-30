#include <iostream>
#include "temperature.h"

using namespace std;

int main()
{
    Temperature t1;
    Temperature t2(31.5, 'f');
    Temperature t3(12.6,'Z');
    //t3.Set(12.5,'f');
    t3.Show();
    
    t2.Show();
   
   
    t2.Convert('c');
    t2.Show();
    t2.Convert('F');
    t2.Show();
    t2.Convert('K');
    t2.Show();
    cout<<t1.Compare(t2)<<' '<<t2.Compare(t1)<<endl;
    
    
    cout << "\nTemperature t1 is: ";
    t1.Show();
    cout << "\nTemperature t2 is: ";
    t2.Show();
    
    t1.Input();
    cout << "\nTemperature t1 is: ";
    t1.Show();
    
    t1.SetFormat('L');
    cout << "\nTemperature t1 is: ";
    t1.Show();
    t2.Show();
    t1.Increment(5,'c');
    t1.Show();
    
   }
