// https://www.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string decToBin(int n)
    {
        string ans = "";

        while (n > 0)
        {
            int bit = n % 2;
            n = n / 2;
            ans = ans + to_string(bit);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    int findPosition(int N)
    {
        // code here
        string bin = decToBin(N);

        int i = bin.size() - 1;
        int pos;
        int noOfOccurence = 0;

        while (i >= 0)
        {
            if (bin[i] == '1')
            {
                noOfOccurence++;
                pos = bin.size() - i;
            }
            i--;
        }

        if (noOfOccurence == 1)
            return pos;

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends