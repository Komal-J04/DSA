// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        // code here
        int ans = -1, maxi = 0, r = arr.size(), c = arr[0].size();

        for (int i = 0; i < r; i++)
        {
            int j = c - 1, cnt = 0;
            while ((j >= 0) && (arr[i][j] == 1))
            {
                j--;
                cnt++;
            }
            if (cnt > maxi)
            {
                maxi = cnt;
                ans = i;
            }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends