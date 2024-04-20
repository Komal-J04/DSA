// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/rotate-array-by-n-elements-1587115621

// APPROACH 1 - TLE
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        // code here
        for (int i = 0; i < d; i++)
        {
            int x = arr[0];
            for (int i = 0; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[n - 1] = x;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    // taking testcases
    cin >> t;

    while (t--)
    {
        int n, d;

        // input n and d
        cin >> n >> d;

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d, n);

        // printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
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
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        // code here
        d = d % n;
        vector<int> temp;
        for (int i = 0; i < d; i++)
        {
            temp.push_back(arr[i]);
        }
        for (int i = d; i < n; i++)
        {
            arr[i - d] = arr[i];
        }
        for (int i = n - d; i < n; i++)
        {
            arr[i] = temp[i - (n - d)];
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    // taking testcases
    cin >> t;

    while (t--)
    {
        int n, d;

        // input n and d
        cin >> n >> d;

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d, n);

        // printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends