// https://www.geeksforgeeks.org/problems/summed-matrix5834/1

// APPROACH 1 - TLE
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long sumMatrix(long long n, long long q)
    {
        // code here
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (((q - i) > 0) && ((q - i) <= n))
                ans++;
        }
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
        long long n, q;

        cin >> n >> q;

        Solution ob;
        cout << ob.sumMatrix(n, q) << endl;
    }
    return 0;
}
// } Driver Code Ends

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2
// i + j = q => j = q - i
// 1 <= j <= n => 1 <= q - i <= n

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long min(long long a, long long b)
    {
        return a < b ? a : b;
    }
    long long max(long long a, long long b)
    {
        return a > b ? a : b;
    }

    long long sumMatrix(long long n, long long q)
    {
        // code here
        return (q < 2 || q > (n * 2)) ? 0 : abs(max(1, q - n) - min(n, q - 1)) + 1;
        // The expression max(1, q - n) [computes min permissible value of i] - min(n, q - 1) [computer maximum permissible value of i] gives the range of valid i values.
        // However, we are interested in the count of these valid i values, which is range + 1.
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, q;

        cin >> n >> q;

        Solution ob;
        cout << ob.sumMatrix(n, q) << endl;
    }
    return 0;
}
// } Driver Code Ends