class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == k)
            return k;

        int operations = 0;
        unordered_set<int> s;
        for (int i = (n - 1); i >= 0; i--)
        {
            if (nums[i] <= k)
                s.insert(nums[i]);
            operations++;
            if (s.size() == k)
                return operations;
        }

        return operations;
    }
};