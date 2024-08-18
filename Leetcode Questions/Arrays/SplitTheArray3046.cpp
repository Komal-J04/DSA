class Solution
{
public:
    bool isPossibleToSplit(vector<int> &nums)
    {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxi, 0);

        for (int x : nums)
            cnt[x - 1]++;

        for (int x : cnt)
            if (x > 2)
                return false;

        return true;
    }
};