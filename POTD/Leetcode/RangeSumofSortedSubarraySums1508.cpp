// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/submissions/1343812195/?envType=daily-question&envId=2024-08-04

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> subSums;
        const int MOD = 1000000007;
        for (int i = 0; i < n; i++)
        {
            long long s = 0;
            for (int j = i; j < n; j++)
            {
                s += nums[j];
                subSums.push_back(s % MOD);
            }
        }
        sort(subSums.begin(), subSums.end());
        long long s = 0;
        for (int i = (left - 1); i <= (right - 1); i++)
            s = (s + subSums[i]) % MOD; // 1-based indexing

        return s % MOD;
    }
};