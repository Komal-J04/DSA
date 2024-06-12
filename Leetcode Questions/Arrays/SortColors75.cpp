// https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2024-06-12

// ------------------------DUTCH NATIONAL FLAG PROBLEM ALGORITHM------------------------
// The goal is to sort an array of numbers in a single pass.

// SOLUTION 1

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    }
};

// SOLUTION 2

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0, m = 0, e = n - 1;

        while (m <= e)
        {
            if (nums[m] == 0)
            {
                swap(nums[s], nums[m]);
                s++;
                m++;
            }
            else if (nums[m] == 2)
            {
                swap(nums[m], nums[e]);
                e--;
            }
            else
                m++;
        }
    }
};