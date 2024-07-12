// https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2024-07-12

// APPROACH 1 - NAIVE
class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int score = 0;
        int d = s.size() - 1;
        bool xGrter = x > y;
        char m = xGrter ? 'a' : 'b';
        char n = xGrter ? 'b' : 'a';
        int p = xGrter ? x : y;
        int q = xGrter ? y : x;

        int i = 0;
        while (i < d)
        {
            if (s[i] == m && s[i + 1] == n)
            {
                score += p;
                s.erase(i, 2);
                i--;
                if (i < 0)
                    i = 0;
            }
            else
                i++;
        }

        i = 0;

        while (i < d)
        {
            if (s[i] == n && s[i + 1] == m)
            {
                score += q;
                s.erase(i, 2);
                i--;
                if (i < 0)
                    i = 0;
            }
            else
                i++;
        }

        return score;
    }
};

// APPROACH 2 - STACK
class Solution
{
public:
    string remove(string s, string pair)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == pair[1] && !st.empty() && st.top() == pair[0])
            {
                st.pop();
            }
            else
                st.push(c);
        }

        string remaining;
        while (!st.empty())
        {
            remaining += st.top();
            st.pop();
        }

        reverse(remaining.begin(), remaining.end());
        return remaining;
    }
    int maximumGain(string s, int x, int y)
    {
        string highP = x > y ? "ab" : "ba";
        string lowP = (highP == "ab") ? "ba" : "ab";

        string temp1 = remove(s, highP);
        int score = ((s.length() - temp1.length()) / 2) * max(x, y);

        string temp2 = remove(temp1, lowP);
        score += ((temp1.length() - temp2.length()) / 2) * min(x, y);

        return score;
    }
};