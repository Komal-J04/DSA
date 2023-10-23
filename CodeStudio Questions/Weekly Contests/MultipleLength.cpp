#include <bits/stdc++.h>
int multipleLength(vector<int> &a, int n)
{
    long long int prod = 1;
    for (long long int i = 0; i < n; i++)
    {
        prod = prod * a[i];
    }

    if (prod == 0)
        return 1;

    long long int ans = 0;
    long long int i = 0;
    while (prod > 0)
    {
        i++;
        prod = prod >> 1;
    }

    return i;
}
