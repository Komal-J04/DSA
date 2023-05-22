class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowIndex=0;
        int colIndex=col-1;

        while(rowIndex<row && colIndex>=0)
        {
            int element = matrix[rowIndex][colIndex];

            if(element==target) return true;
            if(target<element) colIndex--; //bottom values in a column will be greater than top values
            else rowIndex++; //all values in a row will be lesser than rightmost element in the row 
        }
    }
};