// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0, curr = 0;
        int maxi = *max_element(nums.begin(), nums.end());

        // The max possible AND of subarrays of the array is <= max number, Hence, max contiguous length of maximum number in the array is reqd ans
        for (auto x : nums)
        {
            if (x == maxi)
                curr++;
            else
            {
                ans = max(ans, curr);
                curr = 0;
            }
        }

        // equivalent to ans = max(ans, curr) and then returning ans
        return max(ans, curr);
    }
};