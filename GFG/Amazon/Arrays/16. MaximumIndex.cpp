// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/maximum-index-1587115620

// APPROACH 1 - O(N^2)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        // Your code here
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            for (int j = n - 1; j > i; j--)
            {
                if (x < a[j])
                {
                    ans = max(ans, (j - i));
                    break;
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
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

// APPROACH 2 - O(N)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        // Your code here
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        left[0] = a[0];
        right[n - 1] = a[n - 1];

        for (int i = 1; i < n; i++)
        {
            left[i] = min(left[i - 1], a[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], a[i]);
        }

        int i = 0, j = 0, ans = 0;
        while (i < n && j < n)
        {
            if (left[i] <= right[j])
            {
                ans = max(ans, (j - i));
                j++;
            }
            else
                i++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
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

// APPROACH 3 - O(N)
// the same can be done using leftMin as well

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        // Your code here
        int rightMax[n];
        rightMax[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], a[i]);

        // rightMax[i] = max{ arr[i...(n-1] }

        int maxDist = INT_MIN;
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (rightMax[j] >= a[i])
            {
                maxDist = max(maxDist, j - i);
                j++;
            }
            else // if(rightMax[j] < leftMin[i])
                i++;
        }

        return maxDist;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}
// } Driver Code Ends