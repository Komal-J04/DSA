// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19

class Solution
{
public:
    bool isPossible(int mid, vector<int> &bloomDay, int m, int k, int n)
    {
        int k1 = 0, m1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
                k1++;
            else
                k1 = 0; // we need adjacent flowers

            if (k1 == k)
            {
                m1++;
                k1 = 0;
            }

            if (m1 == m)
                return true;
        }
        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        // if((m*k)>n) return -1; m*k goes beyond range of integers when m & k are large

        int high = *max_element(bloomDay.begin(), bloomDay.end());
        // if((m*k)==n) return high;
        int low = 1, ans = -1;

        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (isPossible(mid, bloomDay, m, k, n))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};