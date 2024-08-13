// https://leetcode.com/problems/combination-sum-ii/submissions/1354542051/?envType=daily-question&envId=2024-08-13

class Solution
{
public:
    void solve(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &result, int i)
    {
        if (target == 0)
        {
            result.push_back(temp);
            return;
        }

        if ((i >= candidates.size()) || (target < 0))
            return;

        for (int j = i; j < candidates.size(); j++)
        {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            if (candidates[j] > target)
                break;
            temp.push_back(candidates[j]);
            solve(candidates, target - candidates[j], temp, result, j + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> result;
        solve(candidates, target, temp, result, 0);

        return result;
    }
};