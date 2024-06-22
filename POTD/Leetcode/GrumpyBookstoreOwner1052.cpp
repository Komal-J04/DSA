// https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21

// APPROACH 1

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int total = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
            {
                total = total + customers[i];
                customers[i] = 0;
            }
        }

        int ans = 0, extras = 0;

        for (int i = 0; i < n; i++)
        {
            extras += customers[i]; // all those where grumpy[i]=0 have already been made 0, so only those will be added here where grumpy[i]=1
            if ((i + 1) >= minutes)
            {
                ans = max(ans, total + extras);
                int left = (i + 1) - minutes;
                extras -= customers[left];
            }
        }

        return ans;
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

// APPROACH 2 - without modifying the original array
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int ans = 0, total = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            total += (1 - grumpy[i]) * customers[i];
        }

        int windowAll = 0, windowPartial = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            windowAll += customers[i];
            windowPartial += ((1 - grumpy[i]) * customers[i]);
            if (i + 1 >= minutes)
            {
                ans = max(ans, total - windowPartial + windowAll);
                int left = i - minutes + 1;
                windowAll -= customers[left];
                windowPartial -= ((1 - grumpy[left]) * customers[left]);
            }
        }
        return ans;
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

// APPROACH 3 - without modifying the original array

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int total = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
                total = total + customers[i];
        }

        int ans = 0, extras = 0;

        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 1)
                extras += customers[i];
            if ((i + 1) >= minutes)
            {
                ans = max(ans, total + extras);
                int left = (i + 1) - minutes;
                if (grumpy[left] == 1)
                    extras -= customers[left];
            }
        }

        return ans;
    }
};