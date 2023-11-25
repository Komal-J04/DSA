class Solution
{
public:
    vector<int> nextSmallerElement(int *arr, int n)
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

    vector<int> prevSmallerElement(int *arr, int n)
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

    int largestRectangleArea(int *heights, int n)
    {
        int ans = INT_MIN;

        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        for (int i = 0; i < n; i++)
        {
            if (next[i] == -1)
                next[i] = n; // in case all arr elements are equal
            int breadth = next[i] - prev[i] - 1;
            ans = max(ans, heights[i] * breadth);
        }

        return ans;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int ans = largestRectangleArea(M[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i - 1][j];
                else
                    M[i][j] = 0;
            }

            ans = max(ans, largestRectangleArea(M[i], m));
        }

        return ans;
    }
};