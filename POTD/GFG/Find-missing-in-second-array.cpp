// https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    vector<int> findMissing(int a[], int b[], int n, int m)
    {
        // Your code goes here
        unordered_set<int> temp;
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            temp.insert(b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (temp.find(a[i]) == temp.end())
                ans.push_back(a[i]);
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
        int n;
        cin >> n;
        int m;
        cin >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        vector<int> ans;

        Solution ob;
        ans = ob.findMissing(a, b, n, m);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends