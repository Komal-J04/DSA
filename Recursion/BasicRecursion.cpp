#include<iostream>
using namespace std;

int fact(int n)
{
    //base case
    if (n==0) return 1;
    
    //recursive relation
    return n*fact(n-1);
}


int power2(int n)
{
    if(n==0) return 1;

    return 2*power2(n-1);
}

void printCount(int n)
{
    //Base case
    if(n==0) return;

    //Processing
    cout<<n<<" ";

    //Recursive relation
    printCount(n-1);
}

int fibbonacci(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;

    return fibbonacci(n-1) + fibbonacci(n-2);
}

bool checkSorted(int arr[],int idx, int n)
{
    //base case
    if(n==0 || n==1) return true;
    if(idx == n-1) return true;

    return checkSorted(arr,idx+1,n) && (arr[idx]<arr[idx+1]);

}

int sum = 0;
int arraySum(int *arr, int size)
{
    if(size == 0) return 0;
    return arr[0] + arraySum(arr+1,size-1);
}

int main()
{
    int n;
    cout<<"Enter number - ";
    cin>>n;
    cout<<n<<" factorial = "<<fact(n)<<endl;
    cout<<"2^"<<n<<" = "<<power2(n)<<endl;
    printCount(n);
    cout<<endl;
    cout<<n<<"th number in fibonacci series = "<<fibbonacci(n)<<endl;

    int arr[20];
    int size;
    cout<<"Enter elements of array\n";
    cout<<"Enter size of array\n";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array is sorted? - "<<checkSorted(arr,0,size)<<endl;
    cout<<"Sum of elements in array = "<<arraySum(arr,size)<<endl;
}