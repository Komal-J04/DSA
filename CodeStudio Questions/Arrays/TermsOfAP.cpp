#include <bits/stdc++.h>
#include <vector>

vector<int> termsOfAP(int x)
{
    vector<int> ans;
    int n = 1;
    while (ans.size() != x)
    {
        int term = 3 * n + 2;
        if (term % 4 != 0)
            ans.push_back(term);
        n++;
    }
    return ans;
}
