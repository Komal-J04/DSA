// https://leetcode.com/problems/ugly-number-ii/?envType=daily-question&envId=2024-08-18

// APPROACH 1 - DP
class Solution
{
public:
    int min(int a, int b, int c)
    {
        return ((a < b) && (a < c)) ? a : ((b < c) ? b : c);
    }
    int nthUglyNumber(int n)
    {
        vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < n; i++)
        {
            int mul2 = dp[p1] * 2;
            int mul3 = dp[p2] * 3;
            int mul5 = dp[p3] * 5;

            dp[i] = min(mul2, mul3, mul5);

            if (dp[i] == mul2)
                p1++;
            if (dp[i] == mul3)
                p2++;
            if (dp[i] == mul5)
                p3++;
        }
        return dp[n - 1];
    }
};

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2 - HEAP
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> primes = {2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> pq;
        set<int> visited;

        pq.push(1);
        visited.insert(1);

        long curr;

        for (int i = 0; i < n; i++)
        {
            curr = pq.top();
            pq.pop();
            for (int prime : primes)
            {
                long newNo = curr * prime;
                if (visited.find(newNo) == visited.end())
                {
                    pq.push(newNo);
                    visited.insert(newNo);
                }
            }
        }

        return curr;
    }
};