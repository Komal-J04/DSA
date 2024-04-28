// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/intersection-of-two-arrays2404

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
        // Your code goes here
        unordered_set<int> temp;
        for (int i = 0; i < n; i++)
        {
            temp.insert(a[i]);
        }

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            if (temp.find(b[i]) != temp.end())
            {
                temp.erase(b[i]); // it will be counted again if the element appears in b array again
                count++;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends