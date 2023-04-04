#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int>ans;
	int i=0,j=0;
	while(i<arr1.size() && j<arr2.size()){
		if(arr1[i]==arr2[j]){
				ans.push_back(arr1[i]);
				i++;
				j++;
			} else {
				if(arr1[i]<arr2[j]) i++;
				else j++;
			}
	}
	if(ans.size()==0) return {-1};
	return ans;
}