// https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int Maximize(vector<int> &arr)
    {
        // Complete the function
        sort(arr.begin(), arr.end());
        long long s = 0, n = arr.size();
        const long long MOD = 1000000007;
        for (size_t i = 0; i < n; i++)
            s = (s + ((i * arr[i]) % MOD) % MOD);
        return (int)(s % MOD);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends