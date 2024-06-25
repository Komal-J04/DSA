// APPROACH 1

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0, j = 0; i < rows && j < cols; j++)
        {
            int curr = matrix[i][j];
            int p = i, q = j;
            while (p < rows && q < cols)
            {
                if (matrix[p][q] != curr)
                    return false;
                p++;
                q++;
            }
        }

        for (int i = 0, j = 0; i < rows && j < cols; i++)
        {
            int curr = matrix[i][j];
            int p = i, q = j;
            while (p < rows && q < cols)
            {
                if (matrix[p][q] != curr)
                    return false;
                p++;
                q++;
            }
        }

        return true;
    }
};

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int prow = i - 1;
                int pcol = j - 1;
                if (prow >= 0 && prow < m && pcol >= 0 && pcol < n && matrix[prow][pcol] != matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};