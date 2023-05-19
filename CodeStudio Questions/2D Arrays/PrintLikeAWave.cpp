#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int>ans;
    for(int col=0;col<mCols;col++)
    {
        if(col%2==0) //0th, 2nd, 4th.....columns are printed top to bottom
        {
            for(int row=0;row<nRows;row++)
            {
                ans.push_back(arr[row][col]);
            }
        }
        else
        {
            for(int row=nRows-1;row>=0;row--) //1st, 3rd, 5th columns are printed bottom to top
            {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}