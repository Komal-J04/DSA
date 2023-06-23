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

bool linearSearch(int *arr, int size, int elt)
{
    print(arr,size);

    //base case
    if(size == 0) return false;

    //recursive relation
    if(arr[0]==elt)
    {
        return true;
    }
    else return linearSearch(arr+1,size-1,elt);
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

    if(linearSearch(arr,size,elt))
    {
        cout<<"Element found"<<endl;
    }
    else 
    {
        cout<<"Element not found"<<endl;
    }
}