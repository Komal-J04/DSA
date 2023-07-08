#include <bits/stdc++.h>

int minimumNet(int n, int k, vector<bool> fish)
{
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int j = i;
        while (j < n && count < k)
        {
            if (fish[j])
            {
                count++;
                if (count == k)
                {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
            j++;
        }
    }

    if (ans == INT_MAX)
        ans = -1;

    return ans;
}