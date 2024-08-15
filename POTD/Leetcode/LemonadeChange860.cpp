// https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15

// APPROACH 1

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int cnt5 = 0, cnt10 = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                cnt5++;
            else if (bills[i] == 10)
            {
                if (cnt5 > 0)
                {
                    cnt5--;
                    cnt10++;
                }
                else
                    return false;
            }
            else
            {
                if (!(cnt5 > 0))
                    return false;
                if (cnt10 > 0)
                {
                    cnt10--;
                    cnt5--;
                }
                else
                {
                    if (cnt5 >= 3)
                        cnt5 = cnt5 - 3;
                    else
                        return false;
                }
            }
        }
        return true;
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

// APPROACH 2 - SWITCH CASE
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int cnt5 = 0, cnt10 = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            switch (bills[i])
            {
            case 5:
                cnt5++;
                break;
            case 10:
                if (cnt5 > 0)
                {
                    cnt5--;
                    cnt10++;
                }
                else
                    return false;
                break;
            case 20:
                if (cnt10 > 0 && cnt5 > 0)
                {
                    cnt10--;
                    cnt5--;
                }
                else if (cnt5 >= 3)
                    cnt5 -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};