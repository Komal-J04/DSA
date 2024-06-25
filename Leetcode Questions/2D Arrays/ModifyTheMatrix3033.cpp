class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> maxCols(cols);
        for (int j = 0; j < cols; j++)
        {
            int maxi = -1;
            for (int i = 0; i < rows; i++)
            {
                if (matrix[i][j] > maxi)
                    maxi = matrix[i][j];
            }
            maxCols[j] = maxi;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = maxCols[j];
            }
        }

        return matrix;
    }
};