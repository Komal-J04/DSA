// APPROACH 1 - NAIVE

class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int start = 0;
        int ans = 0;
        int n = s.size();

        while (start < n)
        {
            int i = start, curLen = 1;
            while ((i < (n - 1)) && ((s[i + 1] - s[i]) == 1))
            {
                curLen++;
                i++;
            }
            if (curLen > ans)
                ans = curLen;
            start++;
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

// APPROACH 2
class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int start = 0;
        int ans = 0;
        int n = s.size();

        while (start < n)
        {
            int i = start, curLen = 1;
            while ((i < (n - 1)) && ((s[i + 1] - s[i]) == 1))
            {
                curLen++;
                i++;
            }
            if (curLen > ans)
                ans = curLen;
            start = i + 1; // the condition checking is s[i+1]-s[i], which means that i is the current value where the condition hasn't been satisfied and in the next iteration too it wont be satisfied => start is stuck at the same index leading to TLE
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

// APPROACH 3 - space optimized
class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int n = s.size();
        int curr = 1, ans = 1;
        for (int i = 0; i < (n - 1); i++)
        {
            curr = ((s[i + 1] - s[i]) == 1) ? curr + 1 : 1;
            if (curr > ans)
                ans = curr;
        }
        return ans;
    }
};