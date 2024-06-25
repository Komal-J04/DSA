class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int curRow = 0, curCol = 0;
        int lastRow = (n - 1), lastCol = (n - 1);
        int curNo = 1;
        while (curCol <= lastCol || curRow <= lastRow)
        {
            for (int k = curCol; k <= lastCol; k++)
            {
                mat[curRow][k] = curNo;
                curNo++;
            }
            curRow++;

            for (int k = curRow; k <= lastRow; k++)
            {
                mat[k][lastCol] = curNo;
                curNo++;
            }
            lastCol--;

            for (int k = lastCol; k >= curCol; k--)
            {
                mat[lastRow][k] = curNo;
                curNo++;
            }
            lastRow--;

            for (int k = lastRow; k >= curRow; k--)
            {
                mat[k][curCol] = curNo;
                curNo++;
            }
            curCol++;
        }

        return mat;
    }
};