// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19

// APPROACH 1
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < r; i++)
        {
            int miniCol = -1;
            int mini = INT_MAX;
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] < mini)
                {
                    mini = matrix[i][j];
                    miniCol = j;
                }
            }

            bool isMaxi = true;
            for (int k = 0; k < r; k++)
            {
                if (matrix[k][miniCol] > mini)
                {
                    isMaxi = false;
                    break;
                }
            }

            if (isMaxi)
                ans.push_back(mini);
        }

        return ans;
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

// APPROACH 2
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> rowMins(r, INT_MAX);
        vector<int> colMaxs(c, 0);

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int el = matrix[i][j];
                rowMins[i] = min(rowMins[i], el);
                colMaxs[j] = max(colMaxs[j], el);
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int elt = matrix[i][j];
                if (elt == rowMins[i] && elt == colMaxs[j])
                    ans.push_back(elt);
            }
        }

        return ans;
    }
};