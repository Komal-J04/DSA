#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	sort(arr,arr+n);
	return arr[n-1]+arr[0];
}



//This solution takes lesser time than above solution   
#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	int max=arr[0];
	int min=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max) max=arr[i];
		if(arr[i]<min) min=arr[i];
	}
	return max+min;
}