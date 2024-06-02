// SOLUTION 1
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

// SOLUTION 2
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int length = s.size();
        for (int i = 0; i < length / 2; i++)
        {
            swap(s[i], s[length - i - 1]);
        }
    }
};

// SOLUTION 3
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};