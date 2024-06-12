// Count numbers containing 4

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countNumberswith4(int n)
    {
        // code here
        int ans = 0;

        for (int i = 4; i <= n; i++)
        {
            int num = i;
            bool isFound = false;

            while (num > 1)
            {
                if (num % 10 == 4)
                {
                    isFound = true;
                    break;
                }
                num = num / 10;
            }

            if (isFound)
                ans++;
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends