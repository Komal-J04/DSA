// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-arrays/problem/remove-duplicates-in-small-prime-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr, int n)
    {
        // code here
        vector<int> ans;
        ans.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (!(find(ans.begin(), ans.end(), arr[i]) != ans.end()))
                ans.push_back(arr[i]);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        vector<int> result = obj.removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
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

// APPROACH 2 - this approach gives the correct answer, but does not maintain the order of the elements

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr, int n)
    {
        // code here

        sort(arr.begin(), arr.end());
        // unique puts all unique elements at the start of the vector
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        vector<int> result = obj.removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
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

// APPROACH 3 - This approach only works when the product of all distinct primes is fewer than 10^18 and all numbers are prime. The property of primes of having no divisors except 1 or that number itself is used to arrive at the solution. As the array elements are removed from the array, they keep a value(product) which will contain the product of all distinct primes found previously in the array, so that if the element divides the product, they can be sure proved that the element has previously occurred in the array and hence the number will be rejected.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> removeDuplicate(vector<int> &arr, int n)
    {
        // code here
        long long int prod = arr[0];
        int res_ind = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (prod % arr[i] != 0)
            {
                arr[res_ind++] = arr[i];
                prod *= arr[i];
            }
        }
        arr.erase(arr.begin() + res_ind, arr.end());

        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        vector<int> result = obj.removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
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

// APPROACH 4 - can be implemented by HashSet also