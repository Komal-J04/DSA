//SOLUTION 1
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



//SOLUTION 2 - similar to how we do addition from the right side
#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i=n-1;
	int j=m-1;
	int carry=0;
	vector<int>ans;
	while(i>=0 && j>=0)
	{
		int sum = a[i] + b[j] + carry ;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
		j--;		
	}

	//when elements are left in the 1st array but the 2nd array is over
	while(i>=0)
	{
		int sum = a[i] + carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
	}

	while(j>=0)
	{
		int sum = b[j] + carry;
		carry = sum/10;
		sum=sum%10;
		ans.push_back(sum);
		j--;
	}

	//Suppose 999+999 ; carry is left even after adding all digits
	while(carry != 0)
	{
		int sum = carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
	}

	reverse(ans.begin(),ans.end());

	return ans;
}