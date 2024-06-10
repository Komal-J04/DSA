// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/rearrange-an-array-with-o1-extra-space3142

// APPROACH 1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    // with O(1) extra space.
    void arrange(long long arr[], int n)
    {
        // Your code here
        long long temp[n];
        for (int i = 0; i < n; i++)
            temp[i] = arr[arr[i]];
        for (int i = 0; i < n; i++)
            arr[i] = temp[i];
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;
    while (t--)
    {

        int n;
        // size of array
        cin >> n;
        long long A[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        // calling arrange() function
        ob.arrange(A, n);

        // printing the elements
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
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
    // arr: input array
    // n: size of array
    // Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    // with O(1) extra space.
    void arrange(long long arr[], int n)
    {
        // Your code here
        // We can use the formula arr[i] += (arr[arr[i]] % N) * N to encode both the new value (arr[arr[i]]) and the old value at each index. The old value is arr[i] % N and the new value can be extracted by arr[i] // N.

        for (int i = 0; i < n; i++)
        {
            arr[i] += (arr[arr[i]] % n) * n; // %N to retreive old value at index i
        }

        for (int i = 0; i < n; i++)
            arr[i] = arr[i] / n;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;
    while (t--)
    {

        int n;
        // size of array
        cin >> n;
        long long A[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        // calling arrange() function
        ob.arrange(A, n);

        // printing the elements
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends