// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/replace-all-0s-with-5

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends

/*you are required to complete this method*/
int convertFive(int n)
{
    // Your code here
    int res;
    while (n > 0)
    {
        int r = n % 10;
        n = n / 10;
        if (r == 0)
            r = 5;
        res = (res * 10) + r;
    }
    while (res > 0)
    {
        int r = res % 10;
        res = res / 10;
        n = (n * 10) + r;
    }
    return n;
}