class Solution
{
public:
    int countAsterisks(string s)
    {
        int ans = 0;

        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
                count++;

            if (count % 2 == 0 && s[i] == '*')
                ans++;
        }
        return ans;
    }
};