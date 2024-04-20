// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/minimum-distance-between-two-numbers

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minDist(int a[], int n, int x, int y)
    {
        // code here
        bool xPresent = false;
        bool yPresent = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
                xPresent = true;
            if (a[i] == y)
                yPresent = true;
            if (xPresent && yPresent)
                break;
        }
        if (!xPresent || !yPresent)
            return -1;

        int xIndex = -1;
        int yIndex = -1;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
                xIndex = i;
            if (a[i] == y)
                yIndex = i;
            if (xIndex != -1 && yIndex != -1)
            {
                if (xIndex > yIndex)
                    mini = min(mini, xIndex - yIndex);
                else
                    mini = min(mini, yIndex - xIndex);
            }
        }
        return mini;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends