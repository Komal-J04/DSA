class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curSum = 0, sum = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            curSum += nums[i];
            sum = max(sum, curSum);
            if (curSum < 0)
                curSum = 0;
        }
        return sum;
    }
};