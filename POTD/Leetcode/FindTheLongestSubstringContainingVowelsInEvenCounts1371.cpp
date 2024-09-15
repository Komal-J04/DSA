// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        map<char, int> vowelShift;
        vowelShift['a'] = 4;
        vowelShift['e'] = 3;
        vowelShift['i'] = 2;
        vowelShift['o'] = 1;
        vowelShift['u'] = 0;

        int mask = 0, maxi = 0;
        unordered_map<int, int> occurrences;
        occurrences[0] = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (vowelShift.find(s[i]) != vowelShift.end())
                mask ^= (1 << vowelShift[s[i]]);
            cout << mask << " ";
            if (occurrences.find(mask) == occurrences.end())
            {
                occurrences[mask] = i;
            }
            else
            {
                maxi = max(maxi, i - occurrences[mask]);
            }
        }

        return maxi;
    }
};