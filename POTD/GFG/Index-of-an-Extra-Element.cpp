// https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1

// APPROACH 1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        // add code here.
        set<int> s;

        for (int i = 0; i < (n - 1); i++)
            s.insert(arr2[i]);

        for (int i = 0; i < n; i++)
            if (s.find(arr1[i]) == s.end())
                return i;

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
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

// APPROACH 2

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findExtra(int n, int arr1[], int arr2[])
    {
        // add code here.

        int i = 0, j = 0;

        while (i < n && j < (n - 1))
        {
            while (arr1[i] == arr2[j])
            {
                i++;
                j++;
            }
            return i; // exited out of the while loop because the elements are not equal => extra element
        }

        return i; // if nothing returned so far => last element is the extra element
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends