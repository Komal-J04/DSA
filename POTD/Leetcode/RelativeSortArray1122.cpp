// https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11

// APPROACH 1

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int arr1sz = arr1.size();
        int arr2sz = arr2.size();
        int start = 0;

        for (int i = 0; i < arr2sz; i++)
        {
            int curr = arr2[i];
            for (int j = 0; j < arr1sz; j++)
            {
                if (arr1[j] == curr) // cant break because duplicate elements can be present
                {
                    swap(arr1[j], arr1[start]);
                    start++;
                }
            }
        }

        sort(arr1.begin() + start, arr1.end());
        return arr1;
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

// APPROACH 2 - using a map to store frequencies
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> freq; // elts of arr2 and their frequencies in arr1
        int arr1sz = arr1.size();
        int arr2sz = arr2.size();

        for (int i = 0; i < arr2sz; i++)
            freq[arr2[i]] = 0;

        vector<int> remaining;
        for (int i = 0; i < arr1sz; i++) // if present in arr2, increment count else add to remaining
        {
            if (freq.find(arr1[i]) != freq.end())
                freq[arr1[i]]++;
            else
                remaining.push_back(arr1[i]);
        }
        sort(remaining.begin(), remaining.end());

        vector<int> result;
        for (int i = 0; i < arr2sz; i++)
        {
            while (freq[arr2[i]] != 0)
            {
                result.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }

        for (int i = 0; i < remaining.size(); i++)
            result.push_back(remaining[i]);

        return result;
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

// APPROACH 3 - using a vector to store frequencies
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int arr1sz = arr1.size();
        int arr2sz = arr2.size();
        int maxi = -1;
        for (int i = 0; i < arr1sz; i++)
            if (arr1[i] > maxi)
                maxi = arr1[i];

        vector<int> freq(maxi + 1);
        for (int i = 0; i < arr1sz; i++)
            freq[arr1[i]]++;

        vector<int> result;
        for (int i = 0; i < arr2sz; i++)
        {
            while (freq[arr2[i]] != 0)
            {
                result.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }

        for (int i = 0; i < freq.size(); i++)
        {
            while (freq[i] != 0)
            {
                result.push_back(i);
                freq[i]--;
            }
        }

        return result;
    }
};