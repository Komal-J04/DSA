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

// WHY RESET CNT TO 0 ON ENCOUNTERING AN ODD NUMBER:

/**  When a new odd number is encountered (nums[j] % 2 == 1), it signifies the beginning of counting new subarrays that end at the current position j:
->  Resetting cnt to 0 ensures that we start counting fresh for subarrays that end at this new odd position.
-> Without resetting cnt, it would carry over the count from previous segments, leading to incorrect counts.

*/