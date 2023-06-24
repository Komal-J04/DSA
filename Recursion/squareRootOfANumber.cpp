#include<iostream>
using namespace std;

//int ans = -1;

int sqrt(int num, int start, int end, int ans)
{
    if(start>end) return ans;

    int mid = (start+end)/2;

    int sq = mid * mid;

    if(sq==num)
    {
        ans = mid;
        return ans;
    }

    //cout<<"sq="<<sq<<" ans="<<ans<<endl;

    if(sq>num) return sqrt(num,start,mid-1,ans);
    if(sq<num)
    {
        ans = mid;
        return sqrt(num,mid+1,end,ans);
    }
}

int main()
{
    int num;
    cout<<"Enter number whose square root is to be found - ";
    cin>>num;

    cout<<"sq root = "<<sqrt(num,1,num,-1)<<endl;;

}