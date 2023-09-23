#include <bits/stdc++.h>
int oneIteration(vector<int> A)
{
    int max = INT_MIN;
    int max2 = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > max)
        {
            max2 = max;
            max = A[i];
        }
        else if (A[i] > max2)
        {
            max2 = A[i];
        }
    }
    return max + max2;
}