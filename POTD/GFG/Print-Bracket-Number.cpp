// https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        // Your code goes here
        vector<int> ans;
        stack<int> s;
        int open = 1;
        int i = 0, n = str.size();
        while (i < n)
        {
            if (str[i] == '(')
            {
                ans.push_back(open);
                s.push(open++);
            }
            if (str[i] == ')')
            {
                ans.push_back(s.top());
                s.pop();
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends