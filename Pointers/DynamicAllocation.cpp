#include<iostream>
using namespace std;

void forPrint(int *arr,int n)
{
    cout<<"The array is - ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sum(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    cout<<"Sum of all elements in the array = "<<sum<<endl;
}

int main()
{
    char ch1 ='q';
    cout<<"size of ch1 = "<<sizeof(ch1)<<endl;

    char *ch2 = &ch1;
    cout<<"size of ch2 = "<<sizeof(ch2)<<endl;

    int n;
    cout<<"Enter length of array - ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    forPrint(arr,n);
    sum(arr,n);


}