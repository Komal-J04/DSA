// https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08

// APPROACH 1 - TLE

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < (n - 1); i++)
        {
            int s = nums[i] + nums[i + 1];
            if (s % k == 0)
                return true;

            for (int j = i + 2; j < n; j++)
            {
                s = s + nums[j];
                if (s % k == 0)
                    return true;
            }
        }
        return false;
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

// APPROACH 2 - TLE

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int start = 0;
        int s = 0, i = start;
        while (i < n)
        {
            s = s + nums[i];
            if ((i >= (start + 1)) && (s % k == 0))
                return true; // to ensure that length is at least 2

            if (i == (n - 1))
            {
                start++;
                i = start;
                s = 0;
            }
            else
                i++;
        }
        return false;
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

// APPROACH 3 - SOLUTION

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int prefixMod = 0;
        unordered_map<int, int> modSeen;
        modSeen[0] = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixMod = (prefixMod + nums[i]) % k;

            if (modSeen.find(prefixMod) != modSeen.end())
            {
                // ensures that the size of subarray is atleast 2
                if (i - modSeen[prefixMod] > 1)
                {
                    return 1;
                }
            }
            else
            {
                // mark the value of prefixMod with the current index.
                modSeen[prefixMod] = i;
            }
        }

        return 0;
    }
};