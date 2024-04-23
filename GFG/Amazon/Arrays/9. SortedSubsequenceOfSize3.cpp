// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/sorted-subsequence-of-size-3

// APPROACH 1 - TLE
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int N)
    {
        // Your code here
        vector<int> ans;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (arr[i] < arr[j])
                {
                    for (int k = j + 1; k < N; k++)
                    {
                        if (arr[j] < arr[k])
                        {
                            ans.push_back(arr[i]);
                            ans.push_back(arr[j]);
                            ans.push_back(arr[k]);
                            return ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3)
        {
            cout << -1 << "\n";
        }

        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and
                 isSubSequence(a, res, n, res.size()))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
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

// APPROACH 2 - TLE

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int N)
    {
        // Your code here
        vector<int> ans;
        int start = 0;
        int end = N - 1;
        while (start < end)
        {
            if (arr[start] < arr[end])
            {
                for (int j = start + 1; j < end; j++)
                {
                    if (arr[j] > arr[start] && arr[j] < arr[end])
                    {
                        ans.push_back(arr[start]);
                        ans.push_back(arr[j]);
                        ans.push_back(arr[end]);
                        return ans;
                    }
                }
            }
            else if (arr[start] >= arr[end])
                start++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3)
        {
            cout << -1 << "\n";
        }

        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and
                 isSubSequence(a, res, n, res.size()))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
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

// APPROACH 3 - To find an element which has an element smaller than itself on its left, check if that element is the smallest element while traversing the array from the start index i.e., (0), and to check if there is an element greater than itself on its right side of the array check whether that element is the largest element while traversing from the end of the array i.e., (n-1). If the element is not the smallest element from 0 to that index then it has an element smaller than itself on its left side, and similarly, if the element is not the largest element from that index to the last index then there is a larger element on its right side.

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

// } Driver Code Ends

/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int N)
    {
        // Your code here
        vector<int> ans;

        vector<int> smaller(N, -1); // to store index of element which is smaller than the current element
        smaller[0] = -1;            // 1st element doesn't have a smaller element on its left

        vector<int> larger(N, -1);
        larger[N - 1] = -1;

        int mini = 0;
        int maxi = N - 1;

        for (int i = 1; i < N; i++)
        {
            if (arr[i] <= arr[mini]) // element is less than minimum element found so far
            {
                mini = i;
                smaller[i] = -1; // There is no smaller element on its left hence, smaller[i]=-1;
            }
            else
                smaller[i] = mini;
        }

        for (int i = N - 2; i >= 0; i--)
        {
            if (arr[i] >= arr[maxi])
            {
                maxi = i;
                larger[i] = -1;
            }
            else
                larger[i] = maxi;
        }

        for (int i = 0; i < N; i++)
        {
            if (smaller[i] != -1 && larger[i] != -1)
            {
                ans.push_back(arr[smaller[i]]);
                ans.push_back(arr[i]);
                ans.push_back(arr[larger[i]]);
                return ans;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3)
        {
            cout << -1 << "\n";
        }

        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and
                 isSubSequence(a, res, n, res.size()))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends