// SOLN 1 - brute force
// T.C. - O(n^2)
#include <bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int elt = arr[i];
        int small = INT_MIN;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < elt)
            {
                small = arr[j];
                break;
            }
        }
        if (small == INT_MIN)
            small = -1;
        ans.push_back(small);
    }

    ans.push_back(-1);

    return ans;
}

// SOLN 2 - stack
// T.C. - O(n)
#include <stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--) // for prev smaller elt. for loop from 1 to n-1
    {
        while (st.top() >= arr[i])
            st.pop();

        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}