#include<iostream>
using namespace std;

int main()
{
    int num = 5;

    //address of operator - &
    cout<<"Address of "<<num<<" is "<<&num<<endl;

    int *ptr = &num ;
    cout<<"int Address = "<<ptr<<endl;
    cout<<"int Value at address = "<<*ptr<<endl;
    cout<<"int Size of integer is "<<sizeof(num)<<endl;
    cout<<"int Size of pointer is "<<sizeof(ptr)<<endl;

    double d=4.3;
    double *ptr2 = &d;
    cout<<"double Address = "<<ptr2<<endl;
    cout<<"double Value at address = "<<*ptr2<<endl;
    cout<<"double Size of double is "<<sizeof(d)<<endl;
    cout<<"double Size of pointer is "<<sizeof(ptr2)<<endl;

    
}