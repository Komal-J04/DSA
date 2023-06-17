#include<iostream>
using namespace std;

int main()
{
    int arr[5]={1,2,3,4,5};
    char ch[5]={'a','b','c','d','e'};

    //difference in implementation of cout
    cout<<arr<<" "<<ch<<endl;

    //because of difference in implementation of cout
    char *c = &ch[0];
    int *ptr = &arr[0];
    cout<<c<<" "<<ptr<<endl;
}