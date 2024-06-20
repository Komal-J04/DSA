// https://www.geeksforgeeks.org/problems/magical-box5306/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    double maxVolume(double perimeter, double area)
    {
        // code here
        double length = (perimeter - pow(((perimeter * perimeter) - (24 * area)), 0.5)) / 12;

        return length * ((area / 2) - ((length * perimeter) / 4) + (length * length));
    }
};

//{ Driver Code Starts.
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends