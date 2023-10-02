class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        vector<int> allNums;
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {
            allNums.push_back(i);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (!((nums[i] ^ allNums[i]) == 0))
                return i; // if the xor is zero, that means the number is present in the nums array
        }
        return n; // if all the numbers from 0 to (n-1) is present in the array => return n
    }
};

// Soln 2
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        return (((n) * (n + 1)) / 2) - sum;
    }
};