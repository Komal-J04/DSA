#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n ;i++)
    {
        int maxi=arr[i];
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

//more optimised
#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
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

