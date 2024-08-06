class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> cnt(26, 0);
        for (auto x : word)
            cnt[x - 97]++;

        sort(cnt.begin(), cnt.end(), greater<>());

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 0)
                break;
            ans += ((i / 8) + 1) * cnt[i];
        }

        return ans;
    }
};