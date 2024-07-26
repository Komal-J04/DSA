// https://www.geeksforgeeks.org/problems/k-pangrams0909/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool kPangram(string str, int k)
    {
        // code here
        vector<int> present(26, 0);
        int n = str.size();

        for (int i = 0; i < n; i++)
        {
            if (str[i] != ' ')
                present[str[i] - 'a']++;
        }

        bool isPangram = true;
        int count = 0;
        int missing = 0;
        for (int i = 0; i < 26; i++)
        {
            if (present[i] == 0)
            {
                isPangram = false;
                missing++;
            }
            count += present[i];
        }

        if (isPangram)
            return true;
        if (count < 26)
            return false;

        if (missing <= k)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends