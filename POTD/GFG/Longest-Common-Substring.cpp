// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        // your code here
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
        int result = 0;

        for (int i = 1; i <= str1.size(); i++)
        {
            for (int j = 1; j <= str2.size(); j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = max(result, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends