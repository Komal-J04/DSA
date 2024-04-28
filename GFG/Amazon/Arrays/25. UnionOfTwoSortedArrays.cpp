// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/union-of-two-sorted-arrays-1587115621

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // Your code here
        // return vector with correct order of elements
        vector<int> ans;

        for (int i = 0; i < n; i++)
            ans.push_back(arr1[i]);
        for (int i = 0; i < m; i++)
            ans.push_back(arr2[i]);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
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
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // Your code here
        // return vector with correct order of elements
        vector<int> ans;
        unordered_set<int> temp;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] == arr2[j] && temp.find(arr1[i]) == temp.end())
            {
                ans.push_back(arr1[i]);
                temp.insert(arr1[i]);
                i++;
                j++;
            }
            else if (arr1[i] < arr2[j])
            {
                if (temp.find(arr1[i]) == temp.end())
                    ans.push_back(arr1[i]);
                temp.insert(arr1[i]);
                i++;
            }
            else
            {
                if (temp.find(arr2[j]) == temp.end())
                    ans.push_back(arr2[j]);
                temp.insert(arr2[j]);
                j++;
            }
        }

        while (i < n)
        {
            if (temp.find(arr1[i]) == temp.end())
                ans.push_back(arr1[i]);
            temp.insert(arr1[i]);
            i++;
        }

        while (j < m)
        {
            if (temp.find(arr2[j]) == temp.end())
                ans.push_back(arr2[j]);
            temp.insert(arr2[j]);
            j++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends