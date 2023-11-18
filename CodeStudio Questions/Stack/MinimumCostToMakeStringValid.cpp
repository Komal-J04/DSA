#include <bits/stdc++.h>

bool isValidParenthesis(string s)
{

    if (s.length() == 0)
        return true;

    stack<char> st;

    if (s[0] == ')' || s[0] == '}' || s[0] == ']')
        return false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false; // string is left but stack(opening parentheses) already empty

            if ((s[i] == ']' && st.top() != '[') || (s[i] == '}' && st.top() != '{') || (s[i] == ')' && st.top() != '('))
                return false;

            st.pop();
        }
    }

    if (!st.empty())
        return false;

    return true;
}

int findMinimumCost(string str)
{
    // odd condition
    if (str.length() % 2 != 0)
        return -1;

    if (isValidParenthesis(str))
        return 0;

    // remove valid part
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            st.push(str[i]);

        else if (str[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
                st.push(str[i]);
        }
    }

    // stack contains invalid expression
    int a = 0, b = 0;

    while (!st.empty())
    {
        if (st.top() == '{')
            b++;
        if (st.top() == '}')
            a++;

        st.pop();
    }

    // a=0 or b=0 is also handled here
    return (((a + 1) / 2) + ((b + 1) / 2));
}