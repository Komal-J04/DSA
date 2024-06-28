class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int ans = 0;
        int n = mat.size();

        for (int i = 0, j = 0; i < n && j < n; i++, j++)
        {
            ans += mat[i][j];
            mat[i][j] = 0;
        }

        for (int i = 0, j = (n - 1); i < n && j >= 0; i++, j--)
        {
            ans += mat[i][j];
        }

        return ans;
    }
};