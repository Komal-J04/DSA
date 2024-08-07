//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        vector<int> ans;
        int fRow = 0, fCol = 0;
        int lRow = (r - 1), lCol = (c - 1);

        while (fRow <= lRow || fCol <= lCol)
        {
            for (int i = fCol; i <= lCol; i++)
            {
                ans.push_back(matrix[fRow][i]);
            }
            fRow++;

            if (fRow > lRow || fCol > lCol)
                break;

            for (int i = fRow; i <= lRow; i++)
            {
                ans.push_back(matrix[i][lCol]);
            }
            lCol--;

            if (fRow > lRow || fCol > lCol)
                break;

            for (int i = lCol; i >= fCol; i--)
            {
                ans.push_back(matrix[lRow][i]);
            }
            lRow--;

            if (fRow > lRow || fCol > lCol)
                break;

            for (int i = lRow; i >= fRow; i--)
            {
                ans.push_back(matrix[i][fCol]);
            }
            fCol++;
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
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends