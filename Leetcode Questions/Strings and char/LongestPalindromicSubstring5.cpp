class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 1)
            return s;

        int left, right;
        string longest = "";

        // odd length palindrome
        for (int i = 1; i < n; i++)
        {
            left = i;
            right = i;
            while (s[left] == s[right])
            {
                left--;
                right++;
                if ((left < 0) || (right >= n))
                    break;
            }

            string palin = s.substr(left + 1, right - left - 1);
            longest = (palin.size() > longest.size()) ? palin : longest;
        }

        // even length palindrome
        for (int i = 1; i < n; i++)
        {
            left = i - 1;
            right = i;
            while (s[left] == s[right])
            {
                left--;
                right++;
                if ((left < 0) || (right >= n))
                    break;
            }
            string palin = s.substr(left + 1, right - left - 1);
            longest = (palin.size() > longest.size()) ? palin : longest;
        }

        return ((longest.size() == 0) ? s.substr(0, 1) : longest);
    }
};