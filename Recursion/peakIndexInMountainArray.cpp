#include<iostream>
using namespace std;

void print(int *arr, int size)
{
    cout<<"The array is - ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int ans = -1;

int findPivot(int *arr, int start, int end)
{
    if(start>end) return ans;

    int mid = (start+end)/2;

    if(arr[mid]==arr[start]) 
    {
        ans = mid - 1; //mid-1 will return largest element   mid will return smallest element
        return ans;
    }

    if(arr[mid]>arr[start])
    {
        return findPivot(arr,mid+1,end);
    }
    if(arr[mid]<arr[start])
    {
        return findPivot(arr,start,mid);
    }
}

int  main()
{
    int arr[50];
    int size;
    cout<<"Enter size of array\n";
    cin>>size;
    cout<<"Enter elements of array\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
    print(arr,size);

    cout<<"Peak index in the array is "<<findPivot(arr,0,size-1)<<endl;
}