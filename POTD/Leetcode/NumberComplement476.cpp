// https://leetcode.com/problems/number-complement/submissions/1364213058/?envType=daily-question&envId=2024-08-22

class Solution
{
public:
    string bin(int n)
    {
        string bin = "";
        while (n > 0)
        {
            int r = n % 2;
            n = n / 2;
            bin = to_string(!r) + bin;
        }
        return bin;
    }

    int dec(string binary)
    {
        int power = 0, ans = 0;
        for (int i = binary.size() - 1; i >= 0; i--)
        {
            ans += ((binary[i] - 48) * pow(2, power));
            power += 1;
        }
        return ans;
    }

    int findComplement(int num)
    {
        string binary = bin(num);
        return dec(binary);
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
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        unsigned int mask = ~0;

        while (num & mask)
        {
            mask <<= 1;
        }

        return ~num & ~mask;
    }
};