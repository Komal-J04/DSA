// SOLUTION 1
#include <bits/stdc++.h>

void solve(string str, vector<string> &ans, string output, int index)
{
    if (index >= str.size())
    {
        if (!(output.size() == 0))
            ans.push_back(output); // because we do not want to include empty string
        return;
    }

    // exclude
    solve(str, ans, output, index + 1);

    // include
    output += str[index];
    solve(str, ans, output, index + 1);
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string output;
    int index = 0;
    solve(str, ans, output, index);

    return ans;
}

// SOLUTION 2
#include <bits/stdc++.h>
vector<string> subsequences(string str)
{
    // Write your code here
    vector<string> ans;

    int n = str.length();
    int loop = pow(2, n);

    for (int i = 1; i < loop; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                s += str[j];
        }
        ans.push_back(s);
    }
    return ans;
}