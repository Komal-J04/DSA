// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-searching/problem/square-root

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        // Your code goes here
        if (x == 1)
            return x;

        long long int ans = 0;
        int start = 0;
        int end = x / 2;
        while (start <= end)
        {
            long long int mid = start - ((start - end) / 2);
            if ((mid * mid) == x)
                return mid;
            else if ((mid * mid) < x)
            {
                ans = mid;
                start++;
            }
            else
                end--;
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