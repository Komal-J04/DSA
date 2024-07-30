// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// BACKTRACKING

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSafe(int x, int y, vector<vector<int>> &mat, vector<vector<bool>> &vis, int &n)
    {
        return ((x >= 0) && (x < n) && (y >= 0) && (y < n) && !vis[x][y] && (mat[x][y] == 1));
    }

    void find(int x, int y, vector<vector<int>> mat, string path, vector<string> &ans, vector<vector<bool>> &vis, int n)
    {
        if ((x == (n - 1)) && (y == (n - 1)))
        {
            ans.push_back(path);
            return;
        }

        vis[x][y] = 1;
        if (isSafe(x + 1, y, mat, vis, n))
            find(x + 1, y, mat, path + 'D', ans, vis, n);
        if (isSafe(x, y - 1, mat, vis, n))
            find(x, y - 1, mat, path + 'L', ans, vis, n);
        if (isSafe(x, y + 1, mat, vis, n))
            find(x, y + 1, mat, path + 'R', ans, vis, n);
        if (isSafe(x - 1, y, mat, vis, n))
            find(x - 1, y, mat, path + 'U', ans, vis, n);
        vis[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Your code goes here
        if (mat.empty() || mat[0][0] == 0)
            return {};
        vector<string> ans;
        int n = mat.size();
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        find(0, 0, mat, "", ans, vis, n);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends