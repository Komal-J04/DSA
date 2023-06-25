#include<iostream>
#include<limits.h>
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
    bool swapped = false;
    for(int i=0;i<n ;i++)
    {
        int maxi=arr[i];
        for(int j=0;j<n-i-1;j++)
        {
          if (arr[j] > arr[j + 1]) 
          {
            swap(arr[j], arr[j + 1]);
            swapped = true;
          }
        }
        if(swapped==false) break; //alread sorted
    }
}

bool isPossibleAns(int *stalls, int cowCount,int start, int end, int stallCount)
{
    int mid = (start+end)/2;
    int cows = 1;
    int lastPlacedCow = stalls[0];

    for(int i=0;i<stallCount;i++)
    {
        if(stalls[i]-lastPlacedCow >= mid)
        {
            cows++;
            lastPlacedCow=stalls[i];
            if(cows==cowCount) return true;
        }
    }
    return false;
}

int aggCows(int *stalls, int cowCount,int start, int end, int ans, int stallCount)
{
    if(start>end) return ans;

    int mid = (start+end)/2;

    if(isPossibleAns(stalls,cowCount,start,end,stallCount))
    {
        ans = mid;
        return aggCows(stalls,cowCount,mid+1,end,ans,stallCount);
    }
    else return aggCows(stalls,cowCount,start,mid-1,ans,stallCount);
}

int main()
{
    int stallCount,cowCount;
    cout<<"Enter number of stalls and number of cows"<<endl;
    cin>>stallCount>>cowCount;

    int *stalls = new int[stallCount];

    cout<<"Enter positions of stalls"<<endl;
    for(int i=0;i<stallCount;i++)
    {
        cin>>stalls[i];
    }

    //print(stalls,stallCount);

    sort(stalls,stallCount);

    //print(stalls,stallCount);

    int end = INT_MIN;
    for(int i=0;i<stallCount;i++)
    {
        end = max(stalls[i],end);
    }

    int ans=-1;

    cout<<"The maximum possible minimum distance between any two cows = "<<aggCows(stalls,cowCount,0,end,ans,stallCount)<<endl; //end will be maximum distance between the given stalls i.e, maximum value - minimum value

    delete[] stalls;
}