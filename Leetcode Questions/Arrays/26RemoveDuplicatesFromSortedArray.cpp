class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1; // we want the 1st number in the array to be undisturbed
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};