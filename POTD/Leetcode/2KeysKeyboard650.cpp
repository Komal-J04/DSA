// https://leetcode.com/problems/2-keys-keyboard/description/?envType=daily-question&envId=2024-08-19

class Solution
{
public:
    int minSteps(int n)
    {
        int factor = 2, steps = 0;

        while (n > 1)
        {
            while (n % factor == 0)
            {
                steps += factor;
                n /= factor;
            }
            factor++;
        }

        return steps;
    }
};