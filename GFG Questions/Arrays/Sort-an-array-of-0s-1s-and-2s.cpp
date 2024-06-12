// https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?page=1&sortBy=submissions

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        int s = 0, m = 0, e = n - 1;

        while (m <= e)
        {
            if (a[m] == 0)
            {
                swap(a[s], a[m]);
                s++;
                m++;
            }
            else if (a[m] == 2)
            {
                swap(a[m], a[e]);
                e--;
            }
            else
                m++;
        }
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
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends