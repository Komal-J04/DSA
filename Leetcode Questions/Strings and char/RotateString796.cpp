class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        int n = s.size();
        int k = 1;
        string rot = s;
        for (int i = 0; i < n; i++)
        {
            for (int i = 0; i < n; i++)
            {
                rot[(i + k) % n] = s[i];
            }
            if (rot == goal)
                return true;
            k++;
        }
        return false;
    }
};