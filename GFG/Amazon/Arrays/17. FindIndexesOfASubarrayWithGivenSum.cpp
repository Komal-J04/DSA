// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/subarray-with-given-sum-1587115621

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        // Your code here
        vector<int> ans;

        if (s == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 0)
                {
                    ans.push_back(i + 1);
                    ans.push_back(i + 1);
                    return ans;
                }
            }
            ans.push_back(-1);
            return ans;
        }

        int start = 0;
        long long curSum = 0;
        for (int i = 0; i < n; i++)
        {
            curSum += arr[i];

            while (curSum > s && start <= i)
            {
                curSum -= arr[start];
                start++;
            }
            // cout<<i<<"-"<<curSum<<";start-"<<start<<endl;

            if (curSum == s)
            {
                ans.push_back(start + 1);
                ans.push_back(i + 1);
                return ans;
            }
        }

        // if the last set of elements(including last element), give the required target, the control will not enter the loop again and the condition curSum==s is not being checked for again,so thats why writing it again
        if (curSum == s)
        {
            ans.push_back(start + 1);
            ans.push_back(n);
            return ans;
        }

        ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends