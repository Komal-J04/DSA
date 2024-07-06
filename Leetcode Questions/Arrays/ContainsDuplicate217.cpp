// APPROACH 1
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < (n - 1); i++)
        {
            if (nums[i] == nums[i + 1])
                return true;
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

// APPROACH 2 - using set
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (s.find(nums[i]) == s.end())
                s.insert(nums[i]);
            else
                return true;
        }

        return false;
    }
};