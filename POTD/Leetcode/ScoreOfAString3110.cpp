// https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            ans = ans + abs(s[i] - s[i + 1]);
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

// APPROACH 2 - Recursion
class Solution
{
public:
    int score(string s, int i)
    {
        if (i == s.size())
            return 0;
        return abs(s[i] - s[i - 1]) + score(s, i + 1);
    }
    int scoreOfString(string s)
    {
        int i = 1;
        return score(s, i);
    }
};