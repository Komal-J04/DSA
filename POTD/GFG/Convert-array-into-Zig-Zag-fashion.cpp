// https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

// APPROACH 1 - TLE

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    void zigZag(int n, vector<int> &arr)
    {
        // code here
        sort(arr.begin(), arr.end());    // ascending order
        reverse(arr.begin(), arr.end()); // descending order so that arr[0] < arr[1]  > arr[2]..... after swapping

        for (int i = 0; i < (n - 1); i = i + 2)
            swap(arr[i], arr[i + 1]);
    }
};

//{ Driver Code Starts.

bool isZigzag(int n, vector<int> &arr)
{
    int f = 1;

    for (int i = 1; i < n; i++)
    {
        if (f)
        {
            if (arr[i - 1] > arr[i])
                return 0;
        }
        else
        {
            if (arr[i - 1] < arr[i])
                return 0;
        }
        f = f ^ 1;
    }

    return 1;
}

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;

        obj.zigZag(n, arr);
        bool check = 1;
        check = isZigzag(n, arr);
        if (check)
            cout << "1\n";
        else
            cout << "0\n";
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

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    void zigZag(int n, vector<int> &arr)
    {
        // code here
        for (int i = 1; i < n; i = i + 2)
        {
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
            if (((i + 1) < n) && (arr[i] < arr[i + 1]))
                swap(arr[i], arr[i + 1]);
        }
    }
};

//{ Driver Code Starts.

bool isZigzag(int n, vector<int> &arr)
{
    int f = 1;

    for (int i = 1; i < n; i++)
    {
        if (f)
        {
            if (arr[i - 1] > arr[i])
                return 0;
        }
        else
        {
            if (arr[i - 1] < arr[i])
                return 0;
        }
        f = f ^ 1;
    }

    return 1;
}

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;

        obj.zigZag(n, arr);
        bool check = 1;
        check = isZigzag(n, arr);
        if (check)
            cout << "1\n";
        else
            cout << "0\n";
    }
}

// } Driver Code Ends