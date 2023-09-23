// Searching row-wise
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0;
        int colIndex = col - 1;

        while (rowIndex < row && colIndex >= 0)
        {
            int element = matrix[rowIndex][colIndex];

            if (element == target)
                return true;
            if (target < element)
                colIndex--; // bottom values in a column will be greater than top values
            else
                rowIndex++; // all values in a row will be lesser than rightmost element in the row
        }
    }
};

// Searching column-wise
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = row - 1;
        int colIndex = 0;

        while (rowIndex >= 0 && colIndex < col)
        {
            int element = matrix[rowIndex][colIndex];

            if (element == target)
                return true;
            if (target < element)
                rowIndex--; // bottom values in a column will be greater than top values
            else
                colIndex++; // all values in a row will be lesser than rightmost element in the row
        }

        return false;
    }
};