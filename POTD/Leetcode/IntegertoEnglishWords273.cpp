// https://leetcode.com/problems/integer-to-english-words/description/?envType=daily-question&envId=2024-08-07

class Solution
{
public:
    string helper(int num)
    {
        vector<string> digit{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teen{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> ten{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string result = "";
        if (num > 99)
        {
            result += digit[num / 100] + " Hundred ";
        }
        num %= 100;

        if ((num > 9) && (num < 20))
            result += teen[num - 10] + " ";
        else
        {
            if (num >= 20)
            {
                result += ten[num / 10] + " ";
            }
            num %= 10;
            if (num > 0)
            {
                result += digit[num] + " ";
            }
        }
        return result;
    }

    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        vector<string> bigString{"Thousand", "Million", "Billion"};
        string result = helper(num % 1000);
        num /= 1000;

        for (int i = 0; i < 3; i++) // because we are running for Thousand, Million & Billion (i.e, 3)
        {
            if ((num > 0) && ((num % 1000) > 0))
            {
                result = helper(num % 1000) + bigString[i] + " " + result;
            }
            num /= 1000;
        }

        return result.empty() ? result : result.substr(0, result.size() - 1);
    }
};