// https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double ans = 0;
        double n = customers.size();
        double curTime = customers[0][0];
        double waitTime = 0;

        for (int i = 0; i < n; i++)
        {
            double arrival = customers[i][0];

            if (curTime < arrival)
                curTime = arrival;

            double time = customers[i][1];
            waitTime = waitTime + time + ((curTime > arrival) ? (curTime - arrival) : 0);
            curTime = curTime + time;
        }

        return waitTime / n;
    }
};