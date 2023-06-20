#include<iostream>
using namespace std;

int main()
{
    int rows;
    cout<<"Enter number of rows - ";
    cin>>rows;
    cout<<endl;

    int **arr = new int*[rows];
    int *cols = new int[rows];

    for(int i=0;i<rows;i++)
    {
        int colsInRow;
        cout<<"Enter length of row number "<<(i+1)<<" - ";
        cin>>colsInRow;
        arr[i] = new int [colsInRow];
        cout<<"Enter elements of row number "<<(i+1)<<" - ";
        for(int j=0;j<colsInRow;j++)
        {
            cin>>arr[i][j];
        }
        cols[i] = colsInRow;
        cout<<endl;
    }

    cout<<"Contents of 2D jagged array"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int x=0;x<cols[i];x++)
        {
            cout<<arr[i][x]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<rows;i++)     delete[] arr[i];

    delete[] arr;
}