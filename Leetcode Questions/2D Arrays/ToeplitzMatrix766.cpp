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