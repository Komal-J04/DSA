class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int n = x;
        int ans = 0;
        while (x > 0)
        {
            int r = x % 10;
            x = x / 10;
            if ((ans > (INT_MAX / 10)) | (ans < (INT_MIN / 10)))
                return false;
            ans = ans * 10 + r;
            cout << "ans=" << ans << endl;
        }
        return ans == n;
    }
};

// soln 2 - optimized
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string str = to_string(x);
        int start = 0;
        int end = str.length() - 1;
        while (start <= end)
        {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};