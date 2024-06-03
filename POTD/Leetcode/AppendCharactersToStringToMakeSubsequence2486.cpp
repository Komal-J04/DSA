// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int ans = 0;
        int i = 0, j = 0;
        while (i < s.size() && j < t.size())
        {
            if (t[j] == s[i])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        return t.size() - j;
    }
};