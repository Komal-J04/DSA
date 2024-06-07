class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1}); // 1st row

        for (int i = 0; i < numRows - 1; i++) // because we already have the 1st row, we need to run the loop for numRows-1 times
        {
            vector<int> temp;
            temp.push_back(1); // 1st elt of all rows = 1

            vector<int> curRow = ans[ans.size() - 1];
            for (int k = 0; k < curRow.size() - 1; k++)
            {
                temp.push_back(curRow[k] + curRow[k + 1]);
            }

            temp.push_back(1); // last elt of all rows = 1

            ans.push_back(temp);
        }

        return ans;
    }
};