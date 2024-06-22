class Solution
{
public:
    int secondHighest(string s)
    {
        int n = s.size();
        int i = 0;
        int digit;
        int max = -1;
        int max2 = -1;
        while (i < n)
        {
            if (s[i] >= '0' && s[i] <= '9')
                digit = s[i] - 48;
            if (digit > max)
            {
                max2 = max;
                max = digit;
            }
            else if ((digit > max2) && (digit != max))
                max2 = digit;

            i++;
        }
        return max2;
    }
};