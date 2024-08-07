// https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int PowMod(long long int x, long long int n, long long int M)
    {
        // Code here
        long long int ans = 1;
        x = x % M;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans = ans * x;
                ans = ans % M;
            }
            x = x * x;
            x = x % M;
            n = n >> 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int x, n, m;
        cin >> x >> n >> m;
        Solution ob;
        long long int ans = ob.PowMod(x, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends