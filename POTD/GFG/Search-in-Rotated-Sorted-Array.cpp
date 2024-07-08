// https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPivot(vector<int> arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= arr[0])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }

    int search(vector<int> arr, int key, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &arr, int key)
    {
        // complete the function here
        int pivot = findPivot(arr);

        if ((key >= arr[pivot]) && (key <= arr[arr.size() - 1]))
            return search(arr, key, pivot, arr.size() - 1);
        return search(arr, key, 0, pivot - 1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends