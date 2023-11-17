// T.C. - O(N)      S.C. - O(N) [Stack space]
#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                return true;

            while (!st.empty() && st.top() != '(')
                st.pop(); // pop everything which comes between the opening & closing brackets

            st.pop(); // pop the opening bracket
        }
    }

    return false;
}
