// https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22

// APPROACH 1 - USING MAP
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        map<int, string> m;
        int n = names.size();
        for (int i = 0; i < n; i++)
        {
            m[heights[i]] = names[i];
        }

        int ctr = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            names[ctr] = it->second;
            ctr++;
        }
        reverse(names.begin(), names.end());
        return names;
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

// APPROACH 2 - traversing the map in reverse direction to avoid the time needed for sorting
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        map<int, string> m;
        int n = names.size();
        for (int i = 0; i < n; i++)
        {
            m[heights[i]] = names[i];
        }

        int ctr = 0;
        for (auto it = --m.end(); it != m.begin(); it--)
        {
            names[ctr] = it->second;
            ctr++;
        }
        names[ctr] = m.begin()->second;
        return names;
    }
};