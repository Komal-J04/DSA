class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;

        int start = 1;
        int end = num / 2;
        while (start <= end)
        {
            long long int mid = start - ((start - end) / 2);
            long long square = mid * mid;
            if (square == num)
                return true;
            else if (square < num)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
        ;
    }
};