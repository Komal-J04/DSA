// https://leetcode.com/problems/maximum-distance-in-arrays/submissions/1358114210/?envType=daily-question&envId=2024-08-16

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int mini = arrays[0][0];
        int maxi = arrays[0][arrays[0].size() - 1];
        int n = arrays.size(), ans = 0;

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, max(abs(arrays[i][0] - maxi), abs(arrays[i][arrays[i].size() - 1] - mini)));

            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i][arrays[i].size() - 1]);
        }
        return ans;
    }
};