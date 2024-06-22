// https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool notContains(long long no)
    {
        while (no > 0)
        {
            int r = no % 10;
            if (r == 9)
                return false;
            no = no / 10;
        }
        return true;
    }

    long long ExtractNumber(string sentence)
    {

        // code here
        long long ans = -1;
        int ptr = 0;
        int n = sentence.size();

        while (ptr < n)
        {
            while (!(sentence[ptr] >= '0' && sentence[ptr] <= '9') && ptr < n)
                ptr++;

            long long curr = 0;
            stringstream ss;
            while (sentence[ptr] >= '0' && sentence[ptr] <= '9')
            {
                ss << sentence[ptr];
                ptr++;
            }

            ss >> curr;

            if (notContains(curr) && curr > ans)
                ans = curr;
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
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends