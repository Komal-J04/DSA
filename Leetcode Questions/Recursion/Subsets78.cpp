// SOLUTION 1
class Solution
{
public:
    void solution(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // exclude
        solution(nums, output, index + 1, ans);

        // include
        output.push_back(nums[index]);
        solution(nums, output, index + 1, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solution(nums, output, index, ans);

        return ans;
    }
};

// SOLUTION 2
class Solution
{
public:
    void solution(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // include
        output.push_back(nums[index]);
        solution(nums, output, index + 1, ans);

        // exclude
        output.pop_back();
        solution(nums, output, index + 1, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solution(nums, output, index, ans);

        return ans;
    }
};