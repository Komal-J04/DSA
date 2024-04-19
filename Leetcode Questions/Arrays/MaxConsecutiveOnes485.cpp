class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int maxCount = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                count++;
            else
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        if (nums[n - 1] == 1)
            maxCount = max(maxCount, count); // if last number is also '1', then maxCount will not get updated
        return maxCount;
    }
};