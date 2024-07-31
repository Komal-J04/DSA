// https://www.geeksforgeeks.org/batch/test-series-bundle/track/FTS-mathematics/problem/get-the-diamond

//{ Driver Code Starts
// Initial Template for C++
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long findJumps(long long N, long long K)
    {
        // write your code here
        return (N / K) + (N % K);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        Solution obj;
        cout << obj.findJumps(n, k) << "\n";
    }
}

// } Driver Code Ends