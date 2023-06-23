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

bool binarySearch(int *arr, int size, int elt)
{
    print(arr,size);

    //base case
    if(size==0) return false;

    //processing
    int mid = (size-1) / 2;
    if ( elt == arr[mid] ) return true;

    //recursive relation
    if (elt<arr[mid]) return binarySearch(arr,size/2,elt);
    if(elt>arr[mid]) return  binarySearch(arr+mid+1,size/2,elt);
}

bool binarySearch2(int *arr, int start, int end, int elt)
{
    if(start>end) return false;

    int mid = (start + end )/2;

    if(arr[mid]==elt) return true;
    if(arr[mid]>elt) return binarySearch2(arr,start,mid-1,elt);
    if(arr[mid]<elt) return  binarySearch2(arr,mid+1,end,elt);
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
    
    print(arr,size);

    int elt;
    cout<<"Enter element to be searched - ";
    cin>>elt;

    if(binarySearch2(arr,0,size-1,elt))
    {
        cout<<"Element found"<<endl;
    }
    else 
    {
        cout<<"Element not found"<<endl;
    }
}