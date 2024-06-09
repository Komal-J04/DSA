// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09

// APPROACH 1

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = nums[i];
            if (sum % k == 0)
                ans++;
            for (int j = i + 1; j < n; j++)
            {
                sum += nums[j];
                if (sum % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int ans = 0;

        int cumSum = 0;
        unordered_map<int, int> remainderCount;
        int n = nums.size();

        remainderCount[0] = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            cumSum += nums[i];
            int remainder = cumSum % k;

            if (remainder < 0)
                remainder += k;

            if (remainderCount.find(remainder) != remainderCount.end())
            {
                ans += remainderCount[remainder];
            }

            remainderCount[remainder]++;
        }

        return ans;
    }
};