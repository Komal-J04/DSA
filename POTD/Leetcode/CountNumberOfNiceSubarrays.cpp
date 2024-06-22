// https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size(), cnt = 0, ans = 0, odds = 0;
        while (j < n)
        {
            if (nums[j] % 2 == 1)
            {
                odds++;
                cnt = 0;
            }

            while (odds == k)
            {
                if (nums[i] % 2 == 1)
                    odds--;
                cnt++;
                i++;
            }

            ans = ans + cnt;
            j++;
        }
        return ans;
    }
};