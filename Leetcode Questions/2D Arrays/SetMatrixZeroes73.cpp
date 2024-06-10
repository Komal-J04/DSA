// APPROACH 1 - Inefficient naive approach
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> temp(matrix);

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (temp[i][j] == 0)
                {
                    // all elements of row=0
                    for (int k = 0; k < cols; k++)
                        matrix[i][k] = 0;
                    // all elements of column=0
                    for (int k = 0; k < rows; k++)
                        matrix[k][j] = 0;
                }
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

// APPROACH 2 - using indices
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> indices;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                    indices.push_back({i, j});
            }
        }

        for (int i = 0; i < indices.size(); i++)
        {
            int curRow = indices[i][0];
            int curCol = indices[i][1];

            // make all elements of that row 0
            for (int j = 0; j < cols; j++)
                matrix[curRow][j] = 0;

            // make all elements of that column 0
            for (int j = 0; j < rows; j++)
                matrix[j][curCol] = 0;
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

// APPROACH 3 - use the 1st row and 1 col as flag
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool row1 = false, col1 = false;

        for (int i = 0; i < cols; i++)
        {
            if (matrix[0][i] == 0)
            {
                row1 = true;
                break;
            }
        }

        for (int j = 0; j < rows; j++)
        {
            if (matrix[j][0] == 0)
            {
                col1 = true;
                break;
            }
        }

        // since we have already checked the 1st row & 1st col for 0s, making any elt of that row/col=0 will not lead us towards a wrong answer
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                // if an element of the matrix=0, then make the element of 1st row of that col=0 & 1st col of that row=0 in order to mark that that row and col is to be made 0
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
                    matrix[i][j] = 0;
            }
        }

        if (row1)
        {
            for (int i = 0; i < cols; i++)
                matrix[0][i] = 0;
        }

        if (col1)
        {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
    }
};