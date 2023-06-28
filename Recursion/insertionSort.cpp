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
    if (n <= 1) return;

   sort( arr, n-1 );
   
   int nth = arr[n-1];
   int j = n-2;

   while (j >= 0 && arr[j] > nth)
   {
      arr[j+1] = arr[j];
      j--;
   }
   
   arr[j+1] = nth;
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