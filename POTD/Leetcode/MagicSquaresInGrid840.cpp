// https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09

class Solution
{
public:
    bool isValid(vector<vector<int>> &grid, int p, int q)
    {
        vector<int> cnt(10, 0);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int num = grid[i + p][j + q];
                if ((num < 1) || (num > 9))
                    return false;
                cnt[num]++;
            }
        }

        for (int i = 1; i <= 9; i++)
            if (cnt[i] != 1)
                return false;

        int sum = grid[p][q] + grid[p][q + 1] + grid[p][q + 2];

        for (int i = 0; i < 3; i++)
        {
            if (sum != (grid[p + i][q] + grid[p + i][q + 1] + grid[p + i][q + 2]))
                return false;
        }

        for (int i = 0; i < 3; i++)
        {
            if (sum != (grid[p][q + i] + grid[p + 1][q + i] + grid[p + 2][q + i]))
                return false;
        }

        if (sum != (grid[p][q] + grid[p + 1][q + 1] + grid[p + 2][q + 2]))
            return false;
        if (sum != (grid[p + 2][q] + grid[p + 1][q + 1] + grid[p][q + 2]))
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int cnt = 0, r = grid.size(), c = grid[0].size();
        if ((r < 3) || (c < 3))
            return 0;

        for (int i = 0; i <= r - 3; i++)
        {
            for (int j = 0; j <= c - 3; j++)
            {
                if (isValid(grid, i, j))
                    ++cnt;
            }
        }

        return cnt;
    }
};