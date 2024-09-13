// https://leetcode.com/problems/xor-queries-of-a-subarray/submissions/1388349128/?envType=daily-question&envId=2024-09-13

// APPROACH 1 - NAIVE APPROACH
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (auto x : queries)
        {
            int left = x[0];
            int right = x[1];
            int xorVal = 0;
            for (int i = left; i <= right; i++)
            {
                xorVal = xorVal ^ arr[i];
            }
            ans.push_back(xorVal);
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

// APPROACH 2 - PREFIX SUM
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (int i = 1; i < arr.size(); i++)
        {
            arr[i] = arr[i - 1] ^ arr[i];
        }

        for (auto x : queries)
        {
            int l = x[0];
            int r = x[1];

            if (l == 0)
                ans.push_back(arr[r]);
            else
                ans.push_back(arr[l - 1] ^ arr[r]);
        }

        return ans;
    }
};