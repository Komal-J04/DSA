// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/product-array-puzzle4525

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {

        // code here
        long long int prod = 1;
        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                prod = prod * nums[i];
            else
                zeroCount++;
        }

        vector<long long int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0 && zeroCount == 1)
                ans.push_back(prod); // number 0 and 1 zero
            else if (nums[i] != 0 && zeroCount == 1)
                ans.push_back(0); // number not 0 and 1 zero
            else if (zeroCount > 1)
                ans.push_back(0); // more than 1 zeroes
            else
                ans.push_back(prod / nums[i]); // no zeroes
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends