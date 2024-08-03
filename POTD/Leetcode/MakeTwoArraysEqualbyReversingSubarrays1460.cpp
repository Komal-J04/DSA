// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03

// APPROACH 1

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        if (target == arr)
            return true;

        map<int, int> m;
        for (int i = 0; i < target.size(); i++)
            m[target[i]]++;
        for (int i = 0; i < arr.size(); i++)
        {
            if ((m.find(arr[i]) == m.end()) || (m[arr[i]] == 0))
                return false;
            else
                m[arr[i]]--;
        }

        return true;
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

// APPROACH 2 - MAP TAKES MORE TIME FOR SEARCHING FOR AN ELEMENT, THEREFORE USING A VECTOR TO STORE THE COUNT

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        if (target == arr)
            return true;

        int maxi = *max_element(target.begin(), target.end());
        vector<int> cnt(maxi + 1, 0);

        for (int num : target)
            cnt[num]++;

        for (int i = 0; i < arr.size(); i++)
        {
            if ((arr[i] > maxi) || (cnt[arr[i]] == 0))
                return false;
            cnt[arr[i]]--;
        }

        return true;
    }
};