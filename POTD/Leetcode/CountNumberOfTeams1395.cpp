// https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29

// APPROACH 1 - NAIVE       TC - O(N^3)
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int teams = 0, n = rating.size();

        for (int i = 0; i < n; i++)
        {
            int curri = rating[i];
            for (int j = (i + 1); j < n; j++)
            {
                int currj = rating[j];
                bool inc = false;
                if (curri < currj)
                    inc = true;
                for (int k = (j + 1); k < n; k++)
                {
                    if (inc)
                    {
                        if (currj < rating[k])
                            teams++;
                    }
                    else if (currj > rating[k])
                        teams++;
                }
            }
        }

        return teams;
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

// APPROACH 2  TC - O(N^2)
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int teams = 0, n = rating.size();

        for (int i = 1; i < (n - 1); i++)
        {
            vector<int> L(2), R(2);
            // at position 0, count of the pairs whose comparison results in false will be stored
            for (int j = 0; j < i; j++)
                L[rating[j] < rating[i]]++;
            for (int k = (i + 1); k < n; k++)
                R[rating[i] > rating[k]]++;

            teams += L[0] * R[1] + L[1] * R[0];
        }
        return teams;
    }
};