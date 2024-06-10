// https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

// APPROACH 1 - TLE
void sort(char arr[], int n, unordered_map<int, char> order)
{
    int start = 0; // all values before start are sorted

    for (int i = 0; i < 9; i++)
    {
        char curr = order[i];
        for (int j = start; j < n; j++)
        {
            if (arr[j] == curr)
            {
                swap(arr[start], arr[j]);
                start++;
                break;
            }
        }
    }
}

void matchPairs(int n, char nuts[], char bolts[])
{
    unordered_map<int, char> order;
    order[0] = '!';
    order[1] = '#';
    order[2] = '$';
    order[3] = '%';
    order[4] = '&';
    order[5] = '*';
    order[6] = '?';
    order[7] = '@';
    order[8] = '^';

    sort(nuts, n, order);
    sort(bolts, n, order);
}

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
// User function template for C++
class Solution
{
public:
    void sort(char arr[], int n, unordered_map<char, int> &order)
    {
        auto comparator = [&order](char a, char b)
        {
            return order[a] < order[b];
        };
        std::sort(arr, arr + n, comparator);
    }

    void matchPairs(int n, char nuts[], char bolts[])
    {
        unordered_map<char, int> order;
        order['!'] = 0;
        order['#'] = 1;
        order['$'] = 2;
        order['%'] = 3;
        order['&'] = 4;
        order['*'] = 5;
        order['?'] = 6;
        order['@'] = 7;
        order['^'] = 8;

        sort(nuts, n, order);
        sort(bolts, n, order);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++)
        {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends