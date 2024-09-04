// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03

// APPROACH 1
class Solution
{
public:
    int getLucky(string s, int k)
    {
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            str += to_string(s[i] - 'a' + 1);
        }
        int num = 0;
        for (int i = 0; i < str.size(); i++)
        {
            num += (str[i] - 48);
        }
        --k;

        while (k--)
        {
            int temp = 0;
            while (num > 0)
            {
                temp += (num % 10);
                num /= 10;
            }
            num = temp;
        }

        return num;
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

// APPROACH 2 - Without modifying the original string

class Solution
{
public:
    int singleDig(int num)
    {
        int temp = 0;
        while (num > 0)
        {
            temp += (num % 10);
            num = num / 10;
        }
        return temp;
    }

    int getLucky(string s, int k)
    {
        int num = 0;
        for (char c : s)
        {
            int n = c - 'a' + 1;
            if (n < 10)
                num += n;
            else
            {
                num += singleDig(n);
            }
        }
        --k;

        while (k--)
            num = singleDig(num);
        return num;
    }
};