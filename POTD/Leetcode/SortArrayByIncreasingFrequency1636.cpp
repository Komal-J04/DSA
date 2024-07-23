// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23

// APPROACH 1 - USING VECTOR & LAMBDA FUNCTION

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(201, 0);

        for (int x : nums)
        {
            freq[x + 100]++;
        }

        sort(nums.begin(), nums.end(), [freq](int &x, int &y)
             { return freq[x + 100] == freq[y + 100] ? (x > y) : freq[x + 100] < freq[y + 100]; });

        return nums;
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

// APPROACH 2 - USING MAP & LAMBDA FUNCTION
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        unordered_map<int, int> m;

        for (int x : nums)
            m[x]++;

        sort(nums.begin(), nums.end(), [&](int x, int y)
             { return m[x] == m[y] ? (x > y) : m[x] < m[y]; });

        return nums;
    }
};