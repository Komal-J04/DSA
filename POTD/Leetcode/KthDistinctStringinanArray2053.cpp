// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05

// APPROACH 1 - USING MAP

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> count;
        for (auto s : arr)
            count[s] += 1;
        for (auto s : arr)
        {
            if (count[s] == 1)
            {
                --k;
                if (k == 0)
                    return s;
            }
        }
        return "";
    }
};

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (count(arr.begin(), arr.end(), arr[i]) == 1)
            {
                --k;
                if (k == 0)
                    return arr[i];
            }
        }
        return "";
    }
};