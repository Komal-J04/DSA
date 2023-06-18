#include<iostream>
using namespace std;

void update(int** p2)
{
    p2 = p2 + 1; //No change
    
    *p2 = *p2 + 1; //Yes change

    **p2 = **p2 + 1; //Yes change
}

int main()
{
    int val=5;
    int* ptr=&val;
    int** ptr2 = &ptr;

    cout<<"val = "<<val<<" = "<<*ptr<<" = "<<**ptr2<<endl;
    cout<<"Address of val = "<<&val<<" = "<<ptr<<" = "<<*ptr2<<endl;
    cout<<"Value of ptr = "<<&val<<" = "<<ptr<<" = "<<*ptr2<<endl;
    cout<<"Address of ptr = "<<&ptr<<" = "<<ptr2<<endl;
    cout<<"Value of ptr2 = "<<&ptr<<" = "<<ptr2<<endl;
    cout<<"Address of ptr2 = "<<&ptr2<<endl;

    cout<<"----------------------------------------"<<endl;
    cout<<"Before calling function - "<<ptr2<<" "<<*ptr2<<" "<<**ptr2<<endl;
    update(ptr2);
    cout<<"After calling function - "<<ptr2<<" "<<*ptr2<<" "<<**ptr2<<endl;
    cout<<"----------------------------------------"<<endl;
}