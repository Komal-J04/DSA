#include <bits/stdc++.h> 

//SOLUTION 1 - sorting the entire array using selection sort
int classTest(int n, vector<int> &a, int k) {
    int maxi = 0;
    int p=0;
    for(int i=0;i<n;i++)
    {
        int minIndex=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[minIndex]) minIndex = j;
        }
        swap(a[i],a[minIndex]);
    }
    return a[n-k];
}

//SOLUTION 2 - using bubble sort only k times to get the kth largest element
#include <bits/stdc++.h> 
int classTest(int n, vector<int> &a, int k) {
    for(int i=0;i<k;i++)
    {
        int maxi = a[i];
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    return a[n-k];
}