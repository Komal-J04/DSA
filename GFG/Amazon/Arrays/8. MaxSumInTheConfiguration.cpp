// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/max-sum-in-the-configuration

// APPROACH 1 - NAIVE (Time complexity = O(n^2))

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends

int sumByRotating(int A[], int N)
{
    reverse(A + 1, A + N); // reverse all elements except the 1st
    reverse(A, A + N);     // reverse the entire array

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += i * A[i];
    }
    return sum;
}

int max_sum(int A[], int N)
{
    // Your code here
    int ans = 0;
    int d = N;
    for (int i = 0; i < d; i++)
    {
        int x = sumByRotating(A, N);
        ans = max(ans, x);
    }
    return ans;
}

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2 - Time complexity = O(N)

// When an array is rotated by one, following changes happen in sum of i*arr[i] -
// Multiplier of arr[i-1] changes from 0 to n-1, i.e., arr[i-1] * (n-1) is added to current value.
// Multipliers of other terms is decremented by 1. i.e., (cum_sum - arr[i-1]) is subtracted from current value where cum_sum is sum of all numbers.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends

/*You are required to complete this method*/
int max_sum(int A[], int N)
{
    // Your code here
    int arrSum = 0;
    for (int i = 0; i < N; i++)
    {
        arrSum += A[i];
    }

    // calculating the sum according to the current configuration of the array
    int curr_sum = 0;
    for (int i = 0; i < N; i++)
    {
        curr_sum += i * A[i];
    }

    int ans = curr_sum;

    // sum for current configuration already calculated i.e, 1 configuration already done => N-1 more configurations are left
    for (int i = 1; i < N; i++)
    {
        int next_sum = curr_sum - (arrSum - A[i - 1]) + (A[i - 1] * (N - 1));
        ans = max(ans, next_sum);
        curr_sum = next_sum;
    }

    return ans;
}