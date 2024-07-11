// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11

// APPROACH 1 - RECURSION
class Solution
{
public:
    int i = 0;
    string rev(string s)
    {
        string result;
        while (i < s.length())
        {
            if (s[i] == ')')
            {
                i++;
                reverse(result.begin(), result.end());
                return result;
            }
            else if (s[i] == '(')
            {
                i++;
                result += rev(s);
            }
            else
            {
                result = result + s[i];
                i++;
            }
        }
        return result;
    }
    string reverseParentheses(string s)
    {
        return rev(s);
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

// APPROACH 2 - STACK
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char c = s[i];

            if (c == ')')
            {
                string rev = "";
                while (!st.empty() && st.top() != '(')
                {
                    rev = rev + st.top();
                    st.pop();
                }

                if (!st.empty())
                    st.pop(); // pop the opening bracket

                int sz = rev.size();
                for (int j = 0; j < sz; j++)
                    st.push(rev[j]);
            }
            else
                st.push(c);
        }

        string result = "";
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};