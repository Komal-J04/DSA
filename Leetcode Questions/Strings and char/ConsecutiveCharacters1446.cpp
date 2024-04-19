class Solution
{
public:
    int maxPower(string s)
    {
        int count = 1;
        int maxCount = -1;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                count++;
            else
            {
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};