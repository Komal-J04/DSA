// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/kadanes-algorithm-1587115620

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {

        // Your code here
        long long curSum = 0, sum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            curSum = curSum + arr[i];
            if (curSum > sum)
                sum = curSum;
            if (curSum < 0)
                curSum = 0;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends