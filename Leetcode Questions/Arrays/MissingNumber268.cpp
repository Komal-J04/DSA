class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s = s + nums[i];
        }
        return ((n * (n + 1) / 2)) - s;
    }
};

// SOLUTION 2
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v(n + 1, -1);
        for (int i = 0; i < nums.size(); i++)
        {
            v[nums[i]] = nums[i];
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == -1)
                return i;
        }
        return 0;
    }
};
