// https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int nthStair(int n)
    {
        //  Code here
        return 1 + (n / 2);
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

// The problem of reaching the top of n stairs with steps of 1 or 2 can be reduced to finding unique combinations of 1s and 2s that sum to n.The order of steps does not matter, so combinations like{1, 2, 1} and {2, 1, 1} are considered the same.For ex, when n = 6,
// Start with the Maximum 2s: The first step is to consider the combination with the maximum number of 2s:
// For n = 6, this is {2, 2, 2}.
// Fragment Each 2 into 1s:
// Fragmenting the first 2: {1, 1, 2, 2}.
// Fragmenting the second 2: {1, 1, 1, 1, 2}.
// Fragmenting the third 2: {1, 1, 1, 1, 1, 1}.
// General Formula: For even n, the number of unique ways is 1 + (n / 2). The 1 accounts for the all-2s combination, and (n / 2) counts the combinations formed by fragmenting each 2.