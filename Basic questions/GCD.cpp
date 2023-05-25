//EUCLID ALGORITHM
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    while( a != b )
    {
        if(a>b) a = a - b ;
        if(b>a) b = b - a ;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int a,b;
    cout<<"Enter the 2 numbers"<<endl;
    cin>>a>>b;

    cout<<"GCD of "<<a<<" and "<<b<<" = "<<gcd(a,b)<<endl;
    cout<<"LCM of "<<a<<" and "<<b<<" = "<<lcm(a,b)<<endl;
}