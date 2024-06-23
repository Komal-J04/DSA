// https: // www.geeksforgeeks.org/problems/missing-number-in-array1416/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int> &arr)
    {

        // Your code goes here
        // int s = 0;
        // for(int i=0;i<(n-1);i++) s = s + arr[i];
        // cout<<((n * (n+1))/2) <<" "<<s<<endl;
        // return ((n * (n+1))/2) - s ;

        sort(arr.begin(), arr.end());
        if (arr[0] != 1)
            return 1;
        for (int i = 1; i < (n - 1); i++)
            if ((arr[i] - arr[i - 1]) != 1)
                return (arr[i] + arr[i - 1]) / 2;
        return n;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends