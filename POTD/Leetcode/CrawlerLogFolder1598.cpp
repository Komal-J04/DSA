// https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10

// APPROACH 1

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int n = logs.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (logs[i] == "../")
                (cnt > 0) ? cnt-- : cnt = 0;
            else if (logs[i] == "./")
                continue;
            else
                cnt++;
        }
        return cnt;
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

// APPROACH 2 -

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int cnt = 0;
        for (auto i : logs)
        {
            if (i == "../")
            {
                if (cnt > 0)
                    cnt--;
            }
            else if (i != "./")
                cnt++;
        }
        return cnt;
    }
};