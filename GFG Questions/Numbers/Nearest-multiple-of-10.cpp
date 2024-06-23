// https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1

//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string roundToNearest(string N)
    {
        // Complete the function
        // long long no = 0;
        // long long n = N.size();
        // long long i = 0;
        // while(i < n)
        // {
        //     no = (no * 10) + (N[i] - 48) ;
        //     i++ ;
        // }
        // return (no % 10 > 5) ? to_string(((no/10) * 10) + 10) : to_string((no/10) * 10);

        int n = N.size() - 1;
        int k = N[n] - '0';
        N[n] = '0';

        if (k > 5)
        {
            int carry = 1;
            int sum = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                int key = N[i] - '0' + carry;
                N[i] = static_cast<char>((key % 10) + '0');
                carry = key / 10;
                if (carry == 0)
                    break;
            }
            if (carry)
                N = '1' + N;
        }

        return N;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.roundToNearest(s) << endl;
    }

    return 0;
}
// } Driver Code Ends