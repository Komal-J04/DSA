// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string removeDuplicates(string str)
    {
        // code here
        unordered_set<char> s;
        int i = 0;

        while (i < str.size())
        {
            if (s.find(str[i]) == s.end())
            {
                s.insert(str[i]);
                i++;
            }
            else
                str.erase(i, 1);
        }

        return str;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends