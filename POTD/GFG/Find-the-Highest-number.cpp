// https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPeakElement(vector<int> &a)
    {
        int s = 0, e = a.size() - 1;
        // this will work in case of strictly increasing arrays also because then always a[mid] will be less than a[mid+1] so s++ till s=e
        while (s < e) // in case of strictly increasing s=e at end & the condition s<=e will be satisfied and 1 more iteration will be performed where there is no mid+1 element
        {
            int mid = (s + e) / 2;
            if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
                return a[mid];

            if (a[mid] < a[mid + 1])
                s = mid + 1;
            else
                e = mid;
        }
        return a[s];
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        int ans = ob.findPeakElement(a);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends