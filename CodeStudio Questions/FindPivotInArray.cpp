#include<iostream>
using namespace std;

int Pivot(int arr[],int start,int end)
{
    int mid=start+(end-start)/2;
    while(start<end)
    {
        if(arr[mid]>=arr[0]) start=mid+1;
        else
        {
            end=mid;
        }
        mid=start+(end-start)/2;
    }
    return start;
}

int main()
{
    int size;
    cin>>size;
    int arr[20];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<Pivot(arr,0,6)<<endl;
}