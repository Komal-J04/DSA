// we need to traverse in the reverse direction also because max prod subarray can be at the end of the array as well

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        double prod = 1, rev = 1, maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            prod = prod * nums[i];
            rev = rev * nums[n - i - 1];
            maxi = max({maxi, prod, rev});
            if (prod == 0)
                prod = 1;
            if (rev == 0)
                rev = 1;
        }
        return maxi;
    }
};