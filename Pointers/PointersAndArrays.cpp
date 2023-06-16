#include<iostream>
using namespace std;

int main()
{
    int arr[10]={23,122,41,67};

    cout<<"Address of 1st mem block in arr is "<<arr<<endl;
    cout<<"Address of 1st mem block in arr is "<<&arr[0]<<endl;

    cout<<"*arr = "<<*arr<<endl;
    cout<<"*arr + 1 ="<<*arr + 1<<endl;
    cout<<"*(arr+1)="<<*(arr+1)<<endl; //arr+1 is next value in memory
    cout<<"*arr + 1 ="<<(*arr) + 1<<endl;

    cout<<"arr[2]="<<arr[2]<<endl;
    cout<<"arr[2]="<<*(arr+2)<<endl;

    int i=3;
    cout<<"i[arr]="<<i[arr]<<endl;

    cout<<"-------------------------------------"<<endl;
    //difference in size of array and pointer
    int *p = &arr[0];
    cout<<"size of array="<<sizeof(arr)<<endl;
    cout<<"size of *arr="<<sizeof(*arr)<<endl; //sizeof value at 1st address
    cout<<"size of &arr="<<sizeof(&arr)<<endl; //address of 1st location
    cout<<"size of p="<<sizeof(p)<<endl;
    cout<<"size of *p="<<sizeof(*p)<<endl;
    cout<<"size of &p="<<sizeof(&p)<<endl;

    cout<<"-----------------------------------------"<<endl;
    //difference in and operator
    int a[20]={1,2,3,5};
    cout<<&a[0]<<endl;
    //cout<<&a<<endl;
    //cout<<a<<endl;

    int *ptr = &a[0];
    //cout<<ptr<<endl;
    //cout<<*ptr<<endl;
    cout<<&ptr<<endl;

    cout<<"-------------------------------------------"<<endl;
    //symbol table contents
    //arr = arr + 1;
    ptr = ptr + 1;
    cout<<ptr<<endl;

    return 0;
}