#include <bits/stdc++.h>
int rakshaBandhan(vector<int> arr, int n)
{

    if (n == 0)
        return 0;

    long long int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            sum += arr[i];
            count++;
        }
    }

    // cout<<"Sum = "<<sum<<endl;

    if (sum == 0)
        return 0;
    if (count == n)
        return n;

    while (sum > 0)
    {
        long long int maxNeg = INT_MIN;
        int maxNegIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0 && arr[i] > maxNeg)
            {
                maxNeg = arr[i];
                maxNegIndex = i;
            }
        }
        // cout<<"maxNeg = "<<maxNeg<<endl;
        if ((sum + maxNeg) > 0) // the maxNeg is -ve hence, we add it
        {
            sum += maxNeg;
            count++;
            arr[maxNegIndex] = 0;
        }
        else
        {
            return count;
        }
    }

    return count;
}