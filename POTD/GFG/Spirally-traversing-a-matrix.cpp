// https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &matrix)
    {
        // code here
        vector<int> ans;
        int sRow = 0, eRow = matrix.size() - 1, sCol = 0, eCol = matrix[0].size() - 1;
        while ((sRow <= eRow) || (sCol <= eCol))
        {
            for (int i = sCol; i <= eCol; i++)
                ans.push_back(matrix[sRow][i]);
            sRow++;
            if ((sRow > eRow) || (sCol > eCol))
                break;

            for (int i = sRow; i <= eRow; i++)
                ans.push_back(matrix[i][eCol]);
            eCol--;
            if ((sRow > eRow) || (sCol > eCol))
                break;

            for (int i = eCol; i >= sCol; i--)
                ans.push_back(matrix[eRow][i]);
            eRow--;
            if ((sRow > eRow) || (sCol > eCol))
                break;

            for (int i = eRow; i >= sRow; i--)
                ans.push_back(matrix[i][sCol]);
            sCol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends