#include <bits/stdc++.h>
vector<int> completeSum(vector<int> &a, int n)
{
    // Solution 1
    //  vector<int> compSum;
    //  for(int i=0;i<n;i++)
    //  {
    //      int sum=0;
    //      for(int j=0;j<=i;j++)
    //      {
    //          sum += a[j];
    //      }
    //      compSum.push_back(sum);
    //  }
    //  return compSum;

    // Solution 2 - better approach
    vector<int> compSum(n);
    compSum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        compSum[i] = compSum[i - 1] + a[i];
    }
    return compSum;
}
