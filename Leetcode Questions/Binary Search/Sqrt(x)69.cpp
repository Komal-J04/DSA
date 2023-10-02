class Solution
{
public:
    int solve(int x, int ans)
    {
        int start = 0;
        int end = x;
        while (start <= end)
        {
            long long int mid = start + ((end - start) / 2);
            if (mid * mid == x)
            {
                ans = mid;
                break;
            }
            else if (mid * mid < x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }

    int mySqrt(int x)
    {
        int ans = 0;
        return solve(x, ans);
    }
};