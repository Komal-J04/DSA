// https://leetcode.com/problems/reverse-prefix-of-word/?envType=daily-question&envId=2024-05-01

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                int start = 0;
                int end = i;
                while (start <= end)
                {
                    swap(word[start], word[end]);
                    start++;
                    end--;
                }
                break;
            }
        }
        return word;
    }
};