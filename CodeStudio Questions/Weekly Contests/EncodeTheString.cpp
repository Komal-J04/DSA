#include <bits/stdc++.h>
string encodeString(string &s, int n)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            s[i] += 1;
        }
        else
        {
            s[i] -= 1;
        }
    }
    return s;
}
