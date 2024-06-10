// https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int count = 0;
        int n = heights.size();
        vector<int> temp(heights);
        sort(temp.begin(), temp.end());

        for (int i = 0; i < n; i++)
        {
            if (heights[i] != temp[i])
                count++;
        }

        return count;
    }
};