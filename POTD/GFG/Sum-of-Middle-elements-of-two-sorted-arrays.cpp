// https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// Position this line where user code will be pasted.
class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        // code here
        vector<int> ans;
        int i = 0, j = 0, sz1 = arr1.size(), sz2 = arr2.size();

        while ((i < sz1) && (j < sz2))
        {
            if (arr1[i] < arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else
            {
                ans.push_back(arr2[j]);
                j++;
            }
        }

        while (i < sz1)
        {
            ans.push_back(arr1[i]);
            i++;
        }

        while (j < sz2)
        {
            ans.push_back(arr2[j]);
            j++;
        }
        int sz = ans.size();
        if ((sz % 2) == 1)
            return ans[sz / 2];
        return (ans[(sz / 2) - 1] + ans[sz / 2]);
    }
};

//{ Driver Code Starts.
// Back-end complete function template in C++

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
        {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
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

// } Driver Code Ends
// User function template for C++

// Position this line where user code will be pasted.
class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        // code here
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        sort(arr1.begin(), arr1.end());
        int n = arr1.size();

        if ((n % 2) == 1)
            return arr1[n / 2];
        return arr1[(n / 2) - 1] + arr1[n / 2];
    }
};

//{ Driver Code Starts.
// Back-end complete function template in C++

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
        {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
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

// APPROACH 3
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// Position this line where user code will be pasted.
class Solution
{
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2)
    {
        // code here
        int n1 = arr1.size(), n2 = arr2.size(), i = 0, j = 0, k = 0;

        int a = ((n1 + n2) / 2) - 1;
        int b = (n1 + n2) / 2;

        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                if (k == a)
                {
                    a = arr1[i];
                }
                else if (k == b)
                {
                    b = arr1[i];
                    break;
                }
                i++;
                k++;
            }
            else
            {
                if (k == a)
                {
                    a = arr2[j];
                }
                else if (k == b)
                {
                    b = arr2[j];
                    break;
                }
                j++;
                k++;
            }
        }

        while (i < n1)
        {
            if (k == a)
            {
                a = arr1[i];
            }
            else if (k == b)
            {
                b = arr1[i];
                break;
            }
            i++;
            k++;
        }

        while (j < n2)
        {
            if (k == a)
            {
                a = arr2[j];
            }
            else if (k == b)
            {
                b = arr2[j];
                break;
            }
            j++;
            k++;
        }

        return a + b;
    }
};

//{ Driver Code Starts.
// Back-end complete function template in C++

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2)
        {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends