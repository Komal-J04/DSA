// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/mountain-subarray-problem

// APPROACH 1 - TLE

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q)
    {
        // code here
        vector<bool> ans;
        for (int i = 0; i < q; i++)
        {
            int start = queries[i].first;
            int end = queries[i].second;
            int count = 0;
            for (int j = start; j < end; j++)
            {
                if (a[j] > a[j + 1])
                    count++;
            }
            // descending order=>count=total number of comparisons(end-start) & ascending order=>count=0
            if (count == 0 || count == (end - start))
                ans.push_back(true);
            else // checking for mountain
            {
                while (a[start] <= a[start + 1] && start < end)
                    start++;
                while (a[start] >= a[start + 1] && start < end)
                    start++;

                if (start == end)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++)
        {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v)
        {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
// } Driver Code Ends

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q)
    {
        // code here
        vector<bool> ans;
        for (int i = 0; i < q; i++)
        {
            int start = queries[i].first;
            int end = queries[i].second;

            while (a[start] <= a[start + 1] && start < end)
                start++;
            while (a[start] >= a[start + 1] && start < end)
                start++;

            if (start == end)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++)
        {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v)
        {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
// } Driver Code Ends