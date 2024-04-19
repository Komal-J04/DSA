// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/max-and-second-max

//{ Driver Code Starts
// Initial Template for C++

// CPP code to find largest and
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /* Function to find largest and second largest element
     *sizeOfArray : number of elements in the array
     * arr = input array
     */
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[])
    {
        int max = INT_MIN, max2 = INT_MIN;

        /*********************************
         * Your code here
         * This function should return a
         * vector with first element as
         * max and second element as
         * second max
         * *******************************/

        vector<int> ans;
        int maxIndex = 0;
        for (int i = 0; i < 2; i++)
        {
            maxIndex = 0;

            // find the max elements
            for (int j = 0; j < sizeOfArray; j++)
            {
                if (arr[j] > arr[maxIndex])
                    maxIndex = j;
            }

            // storing the element in a variable beforehand because it will be made -1 in the following loop
            int elt = arr[maxIndex];

            // remove all duplicates
            for (int j = 0; j < sizeOfArray; j++)
            {
                if (arr[j] == elt)
                    arr[j] = -1;
            }

            ans.push_back(elt);
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{

    // Testcase input
    int testcases;
    cin >> testcases;

    // Looping through all testcases
    while (testcases--)
    {
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        // Array input
        for (int index = 0; index < sizeOfArray; index++)
        {
            cin >> arr[index];
        }
        Solution obj;
        vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
        cout << ans[0] << ' ' << ans[1] << endl;
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
// Initial Template for C++

// CPP code to find largest and
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /* Function to find largest and second largest element
     *sizeOfArray : number of elements in the array
     * arr = input array
     */
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[])
    {
        int max = INT_MIN, max2 = INT_MIN;

        /*********************************
         * Your code here
         * This function should return a
         * vector with first element as
         * max and second element as
         * second max
         * *******************************/

        vector<int> ans;
        for (int i = 0; i < sizeOfArray; i++)
        {
            if (arr[i] > max)
            {
                max2 = max;
                max = arr[i];
            }
            else if (arr[i] > max2 && arr[i] != max)
                max2 = arr[i];
        }
        if (max2 == INT_MIN)
            max2 = -1;

        ans.push_back(max);
        ans.push_back(max2);

        return ans;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{

    // Testcase input
    int testcases;
    cin >> testcases;

    // Looping through all testcases
    while (testcases--)
    {
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        // Array input
        for (int index = 0; index < sizeOfArray; index++)
        {
            cin >> arr[index];
        }
        Solution obj;
        vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
}
// } Driver Code Ends