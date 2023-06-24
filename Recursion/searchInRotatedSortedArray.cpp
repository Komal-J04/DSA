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

int findPivot(int *arr, int start, int end)
{
    if(start>end) return -1;

    int mid = (start+end)/2;

    if(arr[mid]==arr[start]) 
    {
        //mid-1 will return largest element   mid will return smallest element
        return mid-1;
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

int search(int *arr, int start, int end, int elt)
{
    if(start>end) return -1;

    int mid = (start+end)/2;

    if(arr[mid]==elt)
    {
        return mid;
    }
    if(elt<arr[mid]) return search(arr,start,mid-1,elt);
    if(elt>arr[mid]) return search(arr,mid+1,end,elt);
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

    int elt;
    cout<<"Enter element to be searched - ";
    cin>>elt;

    int pivot = findPivot(arr,0,size-1);

    if(elt>arr[0]) cout<<search(arr,0,pivot,elt)<<endl;
    else cout<<search(arr,pivot+1,size-1,elt)<<endl;
}