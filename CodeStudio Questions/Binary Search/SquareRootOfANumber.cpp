#include<iostream>
using namespace std;

double morePrecision(int n, int precision, double tempSol)
{
    double factor=1;
    double ans=(double)tempSol;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        for(double j=ans;j*j<=n;j=j+factor)
        {
            ans=j;
        }
    }
    return ans;
}

long long int floorSqrt(long long int N)
{
    // Write your code here.
    long long int ans=0;
    int start=0;
    int end=N;
    long long int mid=0;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(mid*mid == N) return mid;
        else if (mid*mid > N) end=mid-1;
        else if (mid*mid < N)
        {
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<morePrecision(n,3,floorSqrt(n));
}