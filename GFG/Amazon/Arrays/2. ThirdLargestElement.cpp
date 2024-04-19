// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/third-largest-element

// APPROACH 1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int thirdLargest(int a[], int n)
    {
        // Your code here
        int maxIndex; // assume 1st element to be max initially
        for (int i = 0; i < 3; i++)
        {
            maxIndex = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] > a[maxIndex])
                    maxIndex = j;
            }
            if (i != 2)
                a[maxIndex] = -1;
        }
        return a[maxIndex];
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
        Solution obj;
        cout << obj.thirdLargest(a, n) << endl;
    }
}
// } Driver Code Ends

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int thirdLargest(int a[], int n)
    {
        // Your code here
        int first = -1, second = -1, third = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > first)
            {
                third = second;
                second = first;
                first = a[i];
            }
            else if (a[i] > second)
            {
                third = second;
                second = a[i];
            }
            else if (a[i] > third)
                third = a[i];
        }

        return third;
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
        Solution obj;
        cout << obj.thirdLargest(a, n) << endl;
    }
}
// } Driver Code Ends