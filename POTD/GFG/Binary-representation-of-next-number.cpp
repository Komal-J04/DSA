// https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string binaryNextNumber(string s)
    {
        // code here.

        // remove all leading 0's
        int i = 0;
        while (s[i] == '0' && i < s.size())
        {
            s.erase(0, 1);
        }

        // binary representation of n+1 is always making the 1st '0' bit from right to '1' and all the '1's after it to '0'

        int noOnes = 0;
        string temp = "";
        i = s.size() - 1;
        while (s[i] == '1' && i >= 0)
        {
            noOnes++;
            temp += '0';
            i--;
        }

        if (noOnes == s.size())
            s = '1' + temp; // all 1's for ex: 111 then ans = 1000
        else
            s[s.size() - 1 - noOnes] = '1';

        return s.substr(0, s.size() - noOnes) + temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends