// https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1

//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int num(string str, int &ptr, int n)
    {
        stringstream ss;

        while (str[ptr] >= '0' && str[ptr] <= '9' && ptr < n)
        {
            ss << str[ptr];
            ptr++;
        }
        int no;
        ss >> no;
        return no;
    }

    string compareFrac(string str)
    {
        // Code here
        int ptr = 0;
        int n = str.size();
        double a = num(str, ptr, n);
        double b = num(str, ++ptr, n);

        while (!(str[ptr] >= '0' && str[ptr] <= '9') && ptr < n)
            ptr++;

        double c = num(str, ptr, n);
        double d = num(str, ++ptr, n);

        string ans;

        if ((a / b) > (c / d))
            ans = to_string((int)a) + "/" + to_string((int)b);
        else if ((a / b) < (c / d))
            ans = to_string((int)c) + "/" + to_string((int)d);
        else
            ans = "equal";

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends