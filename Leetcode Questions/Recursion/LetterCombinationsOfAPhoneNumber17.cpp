class Solution
{
public:
    void solve(string digits, vector<string> &ans, string output, int index, string mapping[])
    {
        if (index >= digits.size())
        {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0'; // 2
        string val = mapping[number];     // abc
        for (int i = 0; i < val.size(); i++)
        {
            output += val[i];                               // output += a
            solve(digits, ans, output, index + 1, mapping); // to get ad ae & af
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, output, index, mapping);

        return ans;
    }
};