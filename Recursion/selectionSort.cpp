#include<iostream>
#include<limits.h>
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

void sort(int *arr, int n)
{
    if(n==1) return; //n==1 => array is sorted

    //places smallest element at the start
    int mini = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<arr[mini])
        {
            mini = i;
        }
    }

    swap(arr[0],arr[mini]);

    sort(arr+1,n-1);
}

int main()
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
    
    cout<<"Before sorting - ";
    print(arr,size);

    sort(arr,size);

    cout<<"After sorting - ";
    print(arr,size);
}