// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/find-duplicates-in-an-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> duplicates(long long arr[], int n)
    {
        // code here
        int maxElt = -1;
        for (int i = 0; i < n; i++)
        {
            maxElt = maxElt > arr[i] ? maxElt : arr[i];
        }

        vector<int> count(maxElt + 1);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            count[arr[i]]++;
        }

        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] > 1)
                ans.push_back(i); // i is the number whose count>1, not arr[i]]
        }

        sort(ans.begin(), ans.end());

        if (ans.size() == 0)
            ans.push_back(-1);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
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

// APPROACH 2 - space optimization
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> duplicates(long long arr[], int n)
    {
        // code here
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int index = arr[i] % n;
            arr[index] += n; // all the elements in the array are in the range 0 to n-1, so adding n is a way of marking visited as true for that element
        }

        for (int i = 0; i < n; i++)
        {
            if ((arr[i] / n) > 1) // if val>1 => the corresponding value has been encountered >1 times
            {
                ans.push_back(i); // because we have added 'n' to arr[index] i.e, count is according to indices
            }
        }

        sort(ans.begin(), ans.end());

        if (ans.size() == 0)
            ans.push_back(-1);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends