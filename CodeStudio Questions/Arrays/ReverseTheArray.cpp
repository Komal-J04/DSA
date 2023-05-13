#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
    //Solution 1
	int n = arr.size();
	int k = (n+m+1)/2;
	int j = n-1;
	for(int i=m+1;i<k;i++)
	{
		swap(arr[i],arr[j]);
		j--;
	}

    //Solution 2
    int start = m+1;
	int end=arr.size()-1;
	while(start<end)
	{
		swap(arr[start],arr[end]);
		start++;
		end--;
	}
}

vector<int> reverseEntireArray(vector<int> v);
{
    int s=0,e=v.size()-1;
    while(s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}