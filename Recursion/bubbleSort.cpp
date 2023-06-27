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

void sort(int *arr, int n)
{

    if(n==1) return; //n==1 => array is sorted

    //print(arr,n);

    //places largest element at the end
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }

    sort(arr,n-1);
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