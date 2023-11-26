// T.C.-O(n)    S.C.-O(n)
#include <stack>

class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> arr, int n) // O(n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n) // O(n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int ans = INT_MIN;
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        for (int i = 0; i < n; i++) // O(n)
        {
            if (next[i] == -1)
                next[i] = n; // in case all arr elements are equal / last element next = -1
            int breadth = next[i] - prev[i] - 1;
            ans = max(ans, heights[i] * breadth);
        }

        return ans;
    }
};