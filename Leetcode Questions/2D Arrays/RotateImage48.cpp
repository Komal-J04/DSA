//SOLUTION 1
class Solution {
public:
    // void forPrint(vector<vector<int>>arr)
    // {
    //     int r=arr.size();
    //     int c=arr[0].size();
    //     for(int i=0;i<r;i++)
    //     {
    //         for(int j=0;j<c;j++)
    //         {
    //             cout<<arr[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp(matrix);
        int n=matrix.size(); //sqare matrix
        int row=0;
        int col=n-1;
        int count = 0;
        int total= n*n;
        while(count<total)
        {
            for(int i=0,j=0;i<n,j<n;i++,j++)
            {
                matrix[i][col] = temp[row][j];
                //forPrint(matrix);
                count++;
            }
            row++;
            col--;
        }
    }
};




//SOLUTION 2 - Transpose leke reverse
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++) //if we do till <n swaps will happen multiple times
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        int col=n-1;
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};