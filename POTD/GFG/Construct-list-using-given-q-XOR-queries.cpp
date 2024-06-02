// https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1

// APPROACH 1 - TLE
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        // code here
        vector<int> ans;
        ans.push_back(0);

        int noOfQueries = queries.size();

        for (int i = 0; i < noOfQueries; i++)
        {
            if (queries[i][0] == 0)
                ans.push_back(queries[i][1]);
            else
            {
                int no = queries[i][1];
                for (int j = 0; j < ans.size(); j++)
                {
                    ans[j] = ans[j] ^ no;
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
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

// APPROACH 2 - TLE

class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        // code here
        vector<int> ans;
        ans.push_back(0);

        int cumXor = 0;

        for (int i = 0; i < q; i++)
        {
            if (queries[i][0] == 0)
            {
                if (cumXor != 0)
                {
                    for (int j = 0; j < ans.size(); j++)
                        ans[j] = ans[j] ^ cumXor;
                    cumXor = 0;
                }
                ans.push_back(queries[i][1]);
            }
            else
                cumXor = cumXor ^ queries[i][1];
        }

        if (cumXor != 0)
        {
            for (int j = 0; j < ans.size(); j++)
                ans[j] = ans[j] ^ cumXor;
        }

        sort(ans.begin(), ans.end());

        return ans;
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

// APPROACH 3 - Solution
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    vector<int> constructList(int q, vector<vector<int>> &queries)
    {
        // code here
        vector<int> ans;

        int cumXor = 0;

        for (int i = q - 1; i >= 0; i--)
        {
            if (queries[i][0] == 0)
                ans.push_back(queries[i][1] ^ cumXor);
            else
                cumXor = cumXor ^ queries[i][1];
        }

        ans.push_back(cumXor); // initial value of 0 ^ cumXor = cumXor

        sort(ans.begin(), ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends