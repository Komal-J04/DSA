#include<iostream>
#include<limits.h>
using namespace std;

void forPrint(int arr[3][4])
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}

void LinearSearch(int arr[3][4],int target)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            if(arr[row][col]==target)
            {
                cout<<"Element found at row "<<row+1<<" and column "<<col+1<<endl<<endl;
                return;
            }
        }
    }
    cout<<"Element not found"<<endl<<endl;
}

void RowWiseSum(int arr[][4],int rows,int cols)
{
    int maxRow=0;
    int maxSum=INT_MIN;
    for(int row=0;row<rows;row++)
    {
        int sum=0;
        for(int col=0;col<cols;col++)
        {
            sum += arr[row][col];
        }
        if(sum>maxSum) 
        {
            maxSum = sum;
            maxRow = row;
        }
        cout<<"Row "<<row+1<<" sum = "<<sum<<endl;
    }
    cout<<"Row "<<maxRow+1<<" has the largest row sum = "<<maxSum<<endl;
    cout<<endl;
}

void ColumnWiseSum(int arr[][4],int rows,int cols)
{
    int maxCol=0;
    int maxSum=INT_MIN;
    cout<<"Column sum = ";
    for(int col=0;col<cols;col++)
    {
        int sum=0;
        for(int row=0;row<rows;row++) //since the total no. of elements in a column = total no. of rows
        {
            sum += arr[row][col];
        }
        if(sum>maxSum) 
        {
            maxCol = col;
            maxSum=sum;
        }
        cout<<sum<<" ";
    }
    cout<<endl<<"Column "<<maxCol+1<<" has the largest column sum = "<<maxSum<<endl<<endl;
}

int main()
{
    //Create 2D array
    int arr[3][4];

    //Row-wise inputs
    cout<<"Enter elements of the array"<<endl;
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<4;col++)
        {
            cin>>arr[row][col];
        }
    }

    cout<<"Printing the array -"<<endl;
    forPrint(arr);
    cout<<endl;

/*
   //Column wise inputs
   for(int col=0;col<4;col++) //for the columns
   {
      for(int row=0;row<3;row++) //for the rows
      {
         cin>>arr[row][col];
      }
   }

    forPrint(arr);
    cout<<endl;

    int initialisedArr[3][4]={0,1,2,3,4,5,6,7,8,9,0,1};

    forPrint(initialisedArr); //By default, elements are filled in the 1st row, then 2nd row, and so on
    cout<<endl;

    int Arr[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    forPrint(Arr);
    cout<<endl;

*/

    int target;
    cout<<"Enter the element to be searched"<<endl;
    cin>>target;
    LinearSearch(arr,target);

    RowWiseSum(arr,3,4);
    ColumnWiseSum(arr,3,4);

}