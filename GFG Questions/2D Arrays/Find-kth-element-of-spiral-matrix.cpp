//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k)
    {
        // Your code goes here.
        int fRow = 0, lRow = (n - 1);
        int fCol = 0, lCol = (m - 1);

        while (fRow <= lRow || fCol <= lCol)
        {
            for (int i = fCol; i <= lCol; i++)
            {
                k--;
                if (k == 0)
                    return a[fRow][i];
            }
            fRow++;

            for (int i = fRow; i <= lRow; i++)
            {
                k--;
                if (k == 0)
                    return a[i][lCol];
            }
            lCol--;

            for (int i = lCol; i >= fCol; i--)
            {
                k--;
                if (k == 0)
                    return a[lRow][i];
            }
            lRow--;

            for (int i = lRow; i >= fRow; i--)
            {
                k--;
                if (k == 0)
                    return a[i][fCol];
            }
            fCol++;
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int k = 0;
        // cin>>k;
        cin >> n >> m >> k;
        int a[MAX][MAX];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        Solution ob;
        cout << ob.findK(a, n, m, k) << endl;
    }
}
// } Driver Code Ends