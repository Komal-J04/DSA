// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/equilibrium-point-1587115620

// APPROACH 1 - TLE  O(N^2)

//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        // Your code here
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            int sum1 = 0, sum2 = 0;

            for (int j = 0; j < i; j++)
                sum1 += a[j];
            for (int j = i + 1; j < n; j++)
                sum2 += a[j];

            if (sum1 == sum2)
                return i + 1; // given question has 1-based indexing
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
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

// APPROACH 2 - Time complexity = O(N)
//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        // Your code here

        int left[n];
        int right[n];
        int curSumLeft = 0;
        int curSumRight = 0;
        for (int i = 0; i < n; i++)
        {
            left[i] = curSumLeft;
            right[n - i - 1] = curSumRight;

            curSumLeft += a[i];
            curSumRight += a[n - i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (left[i] == right[i])
                return i + 1;
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
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

// APPROACH 3 - Time complexity = O(N)
//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        // Your code here
        int totalSum = 0;

        for (int i = 0; i < n; i++)
            totalSum += a[i];

        int leftSum = 0;

        for (int i = 0; i < n; i++)
        {
            totalSum -= a[i];

            if (leftSum == totalSum)
                return i + 1;

            leftSum += a[i];
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends