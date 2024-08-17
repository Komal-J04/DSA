class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        long long int prod = 1;
        long long int zeroes = 0;
        long long int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeroes++;
            else
                prod = prod * nums[i];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (zeroes == 1 && nums[i] == 0)
                ans.push_back(prod);
            else if (zeroes == 1 && nums[i] != 0)
                ans.push_back(0);
            else if (zeroes > 1)
                ans.push_back(0);
            else
                ans.push_back(prod / nums[i]);
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

// APPROACH 2 - USING PREFIX SUM & SUFFIX SUM
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        vector<int> ans(n, 0);
        pre[0] = 1;
        suf[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = pre[i] * suf[i];
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

// APPROACH 3 - WITHOUT USING SEPARATE ARRAYS FOR PREFIX AND SUFFIX SUM
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix;
            prefix = prefix * nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= suffix;
            suffix = suffix * nums[i];
        }

        return ans;
    }
};
