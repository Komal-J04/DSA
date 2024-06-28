// https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPalindrome(string str)
    {
        int s = 0, e = str.size() - 1;
        while (s <= e)
        {
            if (str[s] != str[e])
                return false;
            s++;
            e--;
        }
        return true;
    }

    string pattern(vector<vector<int>> &arr)
    {
        // Code Here
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            string rowStr = "";
            for (int j = 0; j < n; j++)
            {
                rowStr += to_string(arr[i][j]);
            }
            if (isPalindrome(rowStr))
                return to_string(i) + " R";
        }

        for (int j = 0; j < n; j++)
        {
            string colStr = "";
            for (int i = 0; i < n; i++)
            {
                colStr += to_string(arr[i][j]);
            }
            if (isPalindrome(colStr))
                return to_string(j) + " C";
        }

        return "-1";
    }
};

//{ Driver Code Starts.

int main()
{

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends