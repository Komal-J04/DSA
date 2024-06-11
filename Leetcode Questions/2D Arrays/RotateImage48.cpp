// SOLUTION 1 - Take transpose in another matrix and reverse it
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> transpose;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int j = 0; j < cols; j++)
        {
            vector<int> temp;
            for (int i = 0; i < rows; i++)
            {
                temp.push_back(matrix[i][j]);
            }
            transpose.push_back(temp);
        }

        for (int i = 0; i < transpose.size(); i++)
        {
            reverse(transpose[i].begin(), transpose[i].end());
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = transpose[i][j];
            }
        }
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

// SOLUTION 2
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> temp(matrix);
        int n = matrix.size(); // square matrix
        int row = 0;
        int col = n - 1;
        int count = 0;
        int total = n * n;
        while (count < total)
        {
            for (int i = 0, j = 0; i < n, j < n; i++, j++)
            {
                matrix[i][col] = temp[row][j];
                // forPrint(matrix);
                count++;
            }
            row++;
            col--;
        }
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

// SOLUTION 3 - Transpose leke reverse
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++) // if we do till <n swaps will happen multiple times
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int col = n - 1;
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
