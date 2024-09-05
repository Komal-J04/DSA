// https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int mSum = accumulate(rolls.begin(), rolls.end(), 0);
        int nSum = (mean * (m + n)) - mSum;

        if ((nSum < n) || (nSum > (6 * n)))
            return {};

        vector<int> ans(n, 1);
        nSum -= n;

        for (int i = 0; i < n && nSum > 0; i++)
        {
            int add = min(6 - ans[i], nSum);
            ans[i] += add;
            nSum -= add;
        }

        return ans;
    }
};