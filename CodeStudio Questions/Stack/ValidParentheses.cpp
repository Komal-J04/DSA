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