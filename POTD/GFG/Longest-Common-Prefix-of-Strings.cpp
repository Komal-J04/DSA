// https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        // your code here
        string ans = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int p = arr[i].size(), j = 0;
            while (j < p && j < ans.size() && arr[i][j] == ans[j])
                j++;
            ans.erase(j, ans.size() - j);
        }
        return (ans == "") ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends