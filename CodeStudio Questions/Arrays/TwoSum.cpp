#include<algorithm>

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	sort(arr.begin(),arr.end());

	vector<pair<int,int>> ans;
	
	int start=0;
	int end=n-1;
	
	while(start<end)
	{
		int sum = arr[start] + arr[end];
		if(sum == target)
		{
			ans.push_back({arr[start],arr[end]});			
			start++;
			end--;
		}
		else if ( sum>target)
		{
			end--;
		}
		else start++;
	} 
	
	if(ans.empty()) ans.push_back({-1,-1} );
	return ans;
}
