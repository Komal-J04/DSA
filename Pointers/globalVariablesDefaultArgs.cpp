#include<iostream>
using namespace std;

int score = 15;

void a(int& i){
    cout<<"In a "<<i<<endl;
    cout<<"In a "<<score<<endl;
    //b(i);
}

void b(int& i){
    i++;
    cout<<"In b "<<i<<endl;
    cout<<"In b "<<score<<endl;
}

void printArr(int arr[],int n,int start = 0)
{
    for(int i=start;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int i=5;
    a(i);
    b(i);

    cout<<"In main "<<i<<endl;
    cout<<"In main "<<score<<endl;

    int arr[] = {1,2,3,4,5};
    printArr(arr,5,2);

}