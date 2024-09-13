// https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=daily-question&envId=2024-09-12

// APPROACH 1
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int cnt = 0;
        set<char> s;
        for (auto x : allowed)
            s.insert(x);

        for (int i = 0; i < words.size(); i++)
        {
            string curr = words[i];
            bool found = true;
            for (auto x : curr)
            {
                if (s.find(x) == s.end())
                {
                    found = false;
                    break;
                }
            }
            if (found)
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

// APPROACH 2 - time and space optimization
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int arr[26] = {0};
        for (auto x : allowed)
            arr[x - 'a'] = 1;

        int ans = 0;

        for (string word : words)
        {
            int flag = 1;
            for (char c : word)
            {
                if (arr[c - 'a'] == 0)
                {
                    flag = 0;
                    break;
                }
            }

            ans += flag;
        }

        return ans;
    }
};