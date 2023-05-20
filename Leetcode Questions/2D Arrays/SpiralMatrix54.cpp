//SOLUTION 1
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int noOfRows = matrix.size();
        int noOfCols=matrix[0].size();
        int sRow=0; //left to right
        int sCol=0; //top to bottom
        int eRow=noOfRows-1; //right to left
        int eCol=noOfCols-1; //bottom to top
        int total=noOfRows*noOfCols;
        int count=0;
        while(count<total)
        {
            //Starting row
            for(int col=sCol;col<=eCol && count<total;col++)
            {
                ans.push_back(matrix[sRow][col]);
                count++;
            }
            sRow++;

            //Ending column
            for(int row=sRow;row<=eRow && count<total;row++)
            {
                ans.push_back(matrix[row][eCol]);
                count++;
            }
            eCol--;

            //Ending row
            for(int col=eCol;col>=sCol && count<total;col--)
            {
                ans.push_back(matrix[eRow][col]);
                count++;
            }
            eRow--;

            //Starting column
            for(int row=eRow;row>=sRow && count<total;row--)
            {
                ans.push_back(matrix[row][sCol]);
                count++;
            }
            sCol++;
        }        
        return ans;
    }
};



//SOLUTION 2
class Solution {
public:
    // void forPrint(vector<int>arr)
    // {
    //     cout<<"The vector is -";
    //     for(int i=0;i<arr.size();i++)
    //     {
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int phase=0;
        int startingRow=0; //left to right
        int startingCol=0; //top to bottom
        int endingRow=matrix.size()-1; //right to left
        int endingCol=matrix[0].size()-1; //bottom to top
        int total=matrix.size() * matrix[0].size();
        int count=0;
        while(count<total)
        {
            if(phase==0) //left to right in a row
            {
                for(int col=startingCol;col<=endingCol && count<total;col++)
                {
                    ans.push_back(matrix[startingRow][col]);
                    count++;
                }
                //rowIndex = 1;
                startingRow++;
                phase=1;
            }
            //forPrint(ans);

            if(phase==1) //top to bottom in a column
            {
                for(int row=startingRow;row<=endingRow && count<total;row++)
                {
                    ans.push_back(matrix[row][endingCol]);
                    count++;
                }
                //colIndex=1;
                endingCol--;
                phase=2;
            }
            //forPrint(ans);

            if(phase==2) //right to left in a row
            {
                for(int col=endingCol;col>=startingCol && count<total;col--)
                {
                    ans.push_back(matrix[endingRow][col]);
                    count++;
                }
                //rowIndex=0;
                endingRow--;
                phase=3;
            }
            //forPrint(ans);

            if(phase==3) //bottom to top in a column
            {
                for(int row=endingRow;row>=startingRow && count<total;row--)
                {
                    ans.push_back(matrix[row][startingCol]);
                    count++;
                }
                startingCol++;
                //colIndex=0;
                phase=0;
            }
            //forPrint(ans);
        }        
        return ans;
    }
};