// https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        set<string> s(begin(dictionary), end(dictionary));
        istringstream iss(sentence);
        vector<string> temp;
        string word = "", ans = "";

        while (iss >> word)
            temp.push_back(word);

        for (string str : temp)
        {
            int i = 0;
            while (i++ <= str.size()) // because substr function is taking i characters from 0th position so we need to consider till i=str.size()
            {
                string curr = str.substr(0, i);
                if (s.find(curr) != s.end())
                {
                    ans = ans + curr + " ";
                    break;
                }
                if (i == str.size())
                    ans = ans + str + " ";
            }
        }
        ans.erase(ans.size() - 1);
        return ans;
    }
};

// Optimized approach is using TRIE data structure