// https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24

class Solution
{
public:
    int calc(int a, vector<int> &mapping, int n)
    {
        int place = 1;
        int ans = 0;
        if (a < 10)
            return mapping[a];
        while (a > 0)
        {
            int r = a % 10;
            a = a / 10;
            ans = (mapping[r] * place) + ans;
            place = place * 10;
        }
        return ans;
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return nums;

        sort(nums.begin(), nums.end(), [&](int a, int b)
             { return calc(a, mapping, n) < calc(b, mapping, n); });

        return nums;
    }
};