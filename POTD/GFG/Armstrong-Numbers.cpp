// https://geeksforgeeks.org/problems/armstrong-numbers2727/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string armstrongNumber(int n)
    {
        // code here
        int temp = n;
        int sum = 0;
        while (n > 0)
        {
            int r = n % 10;
            n = n / 10;
            sum = sum + pow(r, 3);
        }
        if (sum == temp)
            return "Yes";
        return "No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends