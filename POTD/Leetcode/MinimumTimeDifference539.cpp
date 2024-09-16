// https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> mins;

        for (auto x : timePoints)
        {
            int h = stoi(x.substr(0, 2));
            int m = stoi(x.substr(3));
            mins.push_back((h * 60) + m);
        }

        sort(mins.begin(), mins.end());
        int minDiff = INT_MAX;

        for (int i = 0; i < (mins.size() - 1); i++)
        {
            minDiff = min(minDiff, mins[i + 1] - mins[i]);
        }

        return min(minDiff, (24 * 60) - mins.back() + mins.front());
    }
};