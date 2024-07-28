class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_set<char> visited;
        unordered_map<char, int> lastOccurence;
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            lastOccurence[s[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited.find(s[i]) == visited.end())
            {
                while (!st.empty() && (st.top() > s[i]) && (lastOccurence[st.top()] > i))
                {
                    visited.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                visited.insert(s[i]);
            }
        }

        s.clear();
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }

        return s;
    }
};