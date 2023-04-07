#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=start + ((end-start)/2);
        if(arr[mid]==key){
            return mid+1;
        }
        else if(key<arr[mid]) end = mid-1;
        else start=mid+1;
    }
    return -1;
}
int main()
{
    int arr[50];
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    cout<<"Enter elements of the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to be searched"<<endl;
    int key;
    cin>>key;
    cout<<"Key found at "<<binarySearch(arr,size,key);
}