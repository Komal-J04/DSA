// https://www.geeksforgeeks.org/problems/remaining-string3515/1

// TC - O(n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    string printString(string s, char ch, int count)
    {
        // Your code goes here
        int i = 0;
        int n = s.size();

        while (i < n && count > 0)
        {
            if (s[i] == ch)
                count--;
            i++;
        }
        return s.substr(i, n - i + 1);
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends