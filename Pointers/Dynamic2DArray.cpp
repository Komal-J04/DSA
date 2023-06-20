#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cout<<"Enter no. of rows and columns - ";
    cin>>m>>n;
    int** arr = new int*[m]; //create 2D array

    for(int i=0;i<m;i++)
    {
        arr[i] = new int[m];
    }

    cout<<"Enter the elements of the array";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"The array is"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //releasing memory
    for(int i=0;i<m;i++)
    {
        delete []arr[i];
    }

    delete []arr;
}