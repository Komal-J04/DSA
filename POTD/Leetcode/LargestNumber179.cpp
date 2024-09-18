// https://leetcode.com/problems/largest-number/submissions/1393946847/?envType=daily-question&envId=2024-09-18

// APPROACH 1 - Static comparator function
class Solution
{
public:
    static bool cmp(string a, string b)
    {
        return (a + b) > (b + a);
    }

    string largestNumber(vector<int> &nums)
    {
        vector<string> temp;
        for (int num : nums)
            temp.push_back(to_string(num));

        sort(temp.begin(), temp.end(), cmp);

        string ans = "";
        for (string num : temp)
            ans += num;

        int i = 0;
        while (i < (ans.size() - 1))
        {
            if (ans[i] != '0')
                break;
            i++;
        }

        return ans.substr(i);
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

// APPROACH 2 - Lambda function
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> temp;
        for (int num : nums)
            temp.push_back(to_string(num));

        sort(temp.begin(), temp.end(), [&](string a, string b)
             { return a + b > b + a; });

        string ans = "";
        for (string num : temp)
            ans += num;

        int i = 0;
        while (i < (ans.size() - 1))
        {
            if (ans[i] != '0')
                break;
            i++;
        }

        return ans.substr(i);
    }
};