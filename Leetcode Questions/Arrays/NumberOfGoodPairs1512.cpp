class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                    count++;
            }
        }
        return count;
    }
};

// Optimized
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int count = 0;

        for (int num : nums)
        {
            count += freq[num];
            freq[num]++;
        }

        return count;
    }
};