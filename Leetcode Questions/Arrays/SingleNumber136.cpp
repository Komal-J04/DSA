class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int x = nums[0];
        int n = nums.size();

        if (n == 1)
            return nums[0];

        for (int i = 1; i < n; i++)
        {
            x = x ^ nums[i];
        }
        return x;
    }
};