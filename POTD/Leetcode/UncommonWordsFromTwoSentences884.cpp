// https://leetcode.com/problems/uncommon-words-from-two-sentences/?envType=daily-question&envId=2024-09-17

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        map<string, int> mp;
        string str;

        istringstream iss(s1);
        while (iss >> str)
            mp[str]++;

        istringstream is(s2);
        while (is >> str)
            mp[str]++;

        vector<string> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == 1)
                ans.push_back(it->first);
        }

        return ans;
    }
};