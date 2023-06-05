#include<iostream>
using namespace std;

int main()
{
    int i=10;

    int *q = &i;
    cout<<"q = "<<q<<endl;
    cout<<"Value at q = "<<*q<<endl;

    //Same thing as the above initialisation in 2 steps
    int *p = 0;
    p = &i;
    cout<<"p = "<<p<<endl;
    cout<<"Value at p = "<<*p<<endl;

    int a = *p;
    cout<<"a = "<<++a<<endl;
    cout<<"i = "<<i<<endl;

    cout<<"Now i = "<< ++*p <<endl;

    //Copying a pointer
    int *ptr = p;
    cout<<"p = "<<p<<" ptr = "<<ptr<<endl;
    cout<<"*p = "<<*p<<" *ptr = "<<*ptr<<endl;

    //Pointer arithmetic
    cout<<"Before : "<<ptr<<endl;
    ++ptr;
    cout<<"After : "<<ptr<<endl;
    cout<<*ptr<<endl; //garbage value
}