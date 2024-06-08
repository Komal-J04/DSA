// https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1

// APPROACH 1 - TLE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx)
    {

        // Your code here
        vector<int> count(maxx + 1); // say maxx=10  count.size() == maxx = 10 (0....9)

        for (int i = 0; i < n; i++)
        {
            for (int j = l[i]; j <= r[i]; j++)
            {
                count[j]++;
            }
        }

        int ans = 0, maxCount = 0;
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] > maxCount)
            {
                maxCount = count[i];
                ans = i;
            }
        }

        return ans;
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
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++)
        {

            cin >> r[i];
            if (r[i] > maxx)
            {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
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
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx)
    {

        // Your code here
        vector<int> count(maxx + 1); // say maxx=10  count.size() == maxx = 10 (0....9)

        // marking the starting and ending of the ranges in a way
        for (int i = 0; i < n; i++)
        {
            count[l[i]]++;
            if (r[i] + 1 <= maxx)
                count[r[i] + 1]--;
        }

        // calculating count of each element using the markingss
        for (int i = 0; i < count.size(); i++)
            count[i] += count[i - 1];

        int ans = 0, maxCount = 0;
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] > maxCount)
            {
                maxCount = count[i];
                ans = i;
            }
        }

        return ans;
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
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++)
        {

            cin >> r[i];
            if (r[i] > maxx)
            {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends