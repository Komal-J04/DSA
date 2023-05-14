#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	int num1 = 0;
	int num2 = 0;
	for(int i=0;i<n;i++)
	{
		num1 = (num1*10) + a[i];
	}
	for(int i=0;i<m;i++)
	{
		num2 = (num2*10) + b[i];
	}
	int sum = num1 + num2 ;
	//cout<<sum<<endl;
	vector<int> ans;
	while(sum>0)
	{
		int r=sum%10;
		sum=sum/10;
		ans.push_back(r);
		// for(int i=0;i<ans.size();i++)
		// {
		// 	cout<<ans[i]<<" ";
		// } cout<<endl;
	}
	int ansSize = ans.size();
	int mid = ansSize/2;
	for(int i=0;i<mid;i++)
	{
		swap(ans[i],ans[ansSize-i-1]);
	}
	return ans;
}