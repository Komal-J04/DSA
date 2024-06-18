// https://leetcode.com/problems/most-profit-assigning-work/?envType=daily-question&envId=2024-06-18

// GREEDY
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int finalProfit = 0;
        map<int, int> mp;

        for (int i = 0; i < difficulty.size(); i++)
        {
            mp[difficulty[i]] = max(mp[difficulty[i]], profit[i]); // in order to handle duplicate entries of difficulties, select the one which gives maximum profit
        }

        sort(worker.begin(), worker.end());
        int maxi = 0;
        auto it = mp.begin();

        for (int i = 0; i < worker.size(); i++)
        {
            int curr = worker[i];

            while (it != mp.end() && curr >= it->first)
            {
                if (it->second > maxi)
                    maxi = it->second;
                it++;
            }

            finalProfit = finalProfit + maxi;
        }

        return finalProfit;
    }
};