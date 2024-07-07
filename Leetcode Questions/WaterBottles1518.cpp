class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int x = numBottles; // number of empty bottles in hand
        int cnt = 0;
        while (x >= numExchange)
        {
            x = x - numExchange + 1;
            cnt++;
        }
        return numBottles + cnt;
    }
};