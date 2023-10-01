class Solution
{
public:
    bool isSafe(vector<vector<int>> m, int x, int y, vector<vector<bool>> visited, int n)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && !visited[x][y])
            return true;
        return false;
    }

    void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, string path, vector<vector<bool>> visited)
    {
        if (x == (n - 1) && y == (n - 1))
        {
            ans.push_back(path);
            return;
        }

        // we have reached (x,y)
        visited[x][y] = 1;

        if (isSafe(m, x, y + 1, visited, n))
        {
            path += 'R';
            solve(m, n, ans, x, y + 1, path, visited);
            path.pop_back(); // on returning from down, remove 'D'
        }

        if (isSafe(m, x, y - 1, visited, n))
        {
            path += 'L';
            solve(m, n, ans, x, y - 1, path, visited);
            path.pop_back();
        }

        if (isSafe(m, x + 1, y, visited, n))
        {
            path += 'D';
            solve(m, n, ans, x + 1, y, path, visited);
            path.pop_back();
        }

        if (isSafe(m, x - 1, y, visited, n))
        {
            path += 'U';
            solve(m, n, ans, x - 1, y, path, visited);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;
        int x = 0;
        int y = 0;
        string path = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        solve(m, n, ans, x, y, path, visited);
        sort(ans.begin(), ans.end());
        return ans;
    }
};