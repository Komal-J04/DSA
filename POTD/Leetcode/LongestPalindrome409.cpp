// https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04

class Solution
{
public:
    int longestPalindrome(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s.size();

        vector<int> count(52, 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                count[s[i] - 'a']++;
            else
                count[s[i] - 'A' + 27]++;
        }

        bool eltWithOneFreq = false; // if there is an element with freq=1, then it can be present at the center of the palindrome
        int ans = 0;
        for (int i = 0; i < 52; i++)
        {
            ans += 2 * (count[i] / 2); // multiplying by 2 because say for abccccdd, for c count[i] / 2 = 2, but actually in the palindrome 4 characters are present &&&&& dividing by 2 for odd frequency
            if (count[i] % 2 == 1)
                eltWithOneFreq = true; // if no elt with 1 freq but an elt with odd freq, then the odd character can also be at the center of the palindrome
        }

        return eltWithOneFreq ? ans + 1 : ans;
    }
};