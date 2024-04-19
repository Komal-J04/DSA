// Solution 1
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        // Storing the last element and shifting all the remaining elements by 1 position to the right and then placing the stored element in the first position of the array
        // Works for small k size only
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            int no = nums[n - 1];
            int p = n - 1;
            while (p > 0)
            {
                nums[p] = nums[p - 1];
                p--;
            }
            nums[0] = no;
        }
    }
};

// Solution 2
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> temp(n, 0); // values will be overwritten if we directly do in nums vector
        for (int i = 0; i < n; i++)
        {
            temp[(i + k) % n] = nums[i];
        }
        // copying temp into original vector since that is to be returned
        for (int i = 0; i < n; i++)
        {
            nums[i] = temp[i];
        }
    }
};

// Solution 3
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> temp(nums);

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            nums[(i + k) % n] = temp[i];
        }
    }
};

// Solution 4
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};