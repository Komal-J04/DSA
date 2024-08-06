// https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
    int isValid(string str)
    {
        // code here
        istringstream iss(str);
        string curr = "";

        while (getline(iss, curr, '.'))
        {
            int number = stoi(curr);
            if ((number < 0) || (number > 255))
                return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends