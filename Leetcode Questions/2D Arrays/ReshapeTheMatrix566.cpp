class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        if (((rows * cols) != (r * c)) || rows == r || cols == c)
            return mat;

        vector<vector<int>> ans(r, vector<int>(c, 0));
        int originalRow = 0, originalCol = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans[i][j] = mat[originalRow][originalCol];

                originalCol++;
                if (originalCol >= cols)
                {
                    originalRow++;
                    originalCol = 0;
                }
                // cout<<ptr[0] - 48<<" "<<ptr[1] - 48<<endl;
            }
        }

        return ans;
    }
};