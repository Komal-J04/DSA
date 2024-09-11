// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11

// APPROACH 1 - Make both of equal lengths by padding the shorter string
class Solution
{
public:
    string bin(int n)
    {
        if (n == 0)
            return "0";

        string ans = "";
        while (n > 0)
        {
            ans += to_string(n % 2);
            n = n / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int minBitFlips(int start, int goal)
    {
        string sBin = bin(start);
        string gBin = bin(goal);

        int maxLength = max(sBin.size(), gBin.size());
        sBin = string(maxLength - sBin.size(), '0') + sBin;
        gBin = string(maxLength - gBin.size(), '0') + gBin;

        int cnt = 0;
        for (int i = 0; i < maxLength; i++)
        {
            if (sBin[i] != gBin[i])
            {
                cnt++;
            }
        }

        return cnt;
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

// APPROACH 2
class Solution
{
public:
    string bin(int n)
    {
        if (n == 0)
            return "0";

        string ans = "";
        while (n > 0)
        {
            ans += to_string(n % 2);
            n = n / 2;
        }
        return ans;
    }

    int minBitFlips(int start, int goal)
    {
        string sBin = bin(start);
        string gBin = bin(goal);

        int cnt = 0, i = 0;
        int maxi = min(sBin.size(), gBin.size());

        for (; i < maxi; i++)
        {
            if (sBin[i] != gBin[i])
                cnt++;
        }

        string longerString = (sBin.size() > gBin.size()) ? sBin : gBin;
        int remainingLength = longerString.size();

        for (; i < remainingLength; i++)
        {
            if (longerString[i] == '1')
                cnt++;
        }

        return cnt;
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

// APPROACH 3
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xorVal = start ^ goal;
        return __builtin_popcount(xorVal);
    }
};