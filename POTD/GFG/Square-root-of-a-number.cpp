// https://www.geeksforgeeks.org/problems/square-root/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int n)
    {
        // Your code goes here
        if (n == 1)
            return 1;
        long long start = 1;
        long long end = n;
        long long ans = 0;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            long long curr = mid * mid;
            if (curr == n)
                return mid;
            else if (curr < n)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
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
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends