// https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int firstElement(int n)
    {
        // code here
        int a00 = 1;
        int a01 = 1;
        int a10 = 1;
        int a11 = 0;

        // from 1 to n because we already have a^1, so, for i=1 a^2 is calculated.....i=n-1 a^n is calculated
        for (int i = 1; i < n; i++)
        {
            int x = a00;
            int y = a10;

            a00 = (a00 + a01) % 1000000007;
            a01 = x;
            a10 = (a10 + a11) % 1000000007;
            a11 = y;
        }

        return a10 % 1000000007;
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
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends