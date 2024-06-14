// https://leetcode.com/problems/minimum-increment-to-make-array-unique/?envType=daily-question&envId=2024-06-14

// APPROACH 1 - TLE

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int moves = 0;
        set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (s.find(nums[i]) == s.end())
            {
                s.insert(nums[i]);
                continue;
            }
            while (s.find(nums[i]) != s.end())
            {
                nums[i]++;
                moves++;
            }
            s.insert(nums[i]);
        }
        return moves;
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
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int increments = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                int increment = nums[i - 1] - nums[i] + 1;
                increments += increment;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return increments;
    }
};