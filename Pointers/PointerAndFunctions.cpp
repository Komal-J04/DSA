#include<iostream>
using namespace std;

void print(int *p)
{
    cout<<"Passing pointer to function "<<*p<<endl;
}

void update(int *p)
{
    cout<<"-----------------------------------"<<endl;
    (*p)++;
    cout<<"*ptr after updating in function "<<*p<<endl;
    p++;
    cout<<"ptr in function "<<p<<endl;
    cout<<"-----------------------------------"<<endl;
}

int getSum(int arr[],int n)
{
    cout<<"in function sizeof(arr)="<<sizeof(arr)<<endl;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum = sum + i[arr]; 
    }
    return sum;
}

int  main()
{
    int i=5;
    int *ptr = &i;

    print(ptr);
    cout<<"ptr before updating "<<ptr<<endl;
    cout<<"*ptr before updating "<<*ptr<<endl;
    update(ptr);
    cout<<"ptr after updating "<<ptr<<endl;
    cout<<"*ptr after updating in main "<<*ptr<<endl;

    int arr[5]={1,2,3,4,5};
    cout<<"sum = "<<getSum(arr+2,3)<<endl;
    cout<<"in main sizeof(arr)="<<sizeof(arr)<<endl;
}