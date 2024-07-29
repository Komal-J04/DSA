// APPROACH 1 - NAIVE       TC - O(N^2)
class Solution
{
public:
    bool check(vector<int> nums, int &n)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
                return false;
        }
        return true;
    }

    void sub(vector<int> &nums, int &n)
    {
        int mini = INT_MAX;

        for (int i = 0; i < n; i++)
            if ((nums[i] != 0) && (nums[i] < mini))
                mini = nums[i];

        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                nums[i] -= mini;
    }

    int minimumOperations(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        while (!check(nums, n))
        {
            sub(nums, n);
            ans++;
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
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != 0)
                s.insert(nums[i]);
        return s.size();
    }
};