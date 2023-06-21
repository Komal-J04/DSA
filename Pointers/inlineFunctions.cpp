#include<iostream>
using namespace std;

inline int func(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    int a = 1;
    int b=2;
    cout<<func(a,b)<<endl;

    a = a + 3;
    b++;

    cout<<func(a,b)<<endl;
}