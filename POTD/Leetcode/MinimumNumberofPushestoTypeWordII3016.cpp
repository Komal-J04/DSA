// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06

// APPROACH 1 - USING MAP

class Solution
{
public:
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    int minimumPushes(string word)
    {
        map<char, int> mp;
        for (auto x : word)
            mp[x]++;

        if (mp.size() <= 8)
            return word.size();

        vector<int> cnt;
        for (auto it = mp.begin(); it != mp.end(); it++)
            cnt.push_back(it->second);

        sort(cnt.begin(), cnt.end(), greater<>());
        print(cnt);
        int ans = 0, curr = 1, no = 0;
        for (int i = 0; i < cnt.size(); i++)
        {
            ans += (cnt[i] * curr);
            ++no;
            if (no == 8)
            {
                no = 0;
                ++curr;
            }
        }

        return ans;
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

// APPROACH 2 - BETTER TIME AND SPACE COMPLEXITIES
class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> cnt(26, 0);
        int unique = 0, ans = 0, curr = 1, no = 0;
        for (auto x : word)
        {
            if (cnt[x - 97] == 0)
                unique++;
            cnt[x - 97]++;
        }
        if (unique <= 8)
            return word.size();

        sort(cnt.begin(), cnt.end(), greater<>());

        for (int i = 0; (i < cnt.size()); i++)
        {
            if (cnt[i] == 0)
                break;

            no++;
            ans += cnt[i] * curr;
            if (no == 8)
            {
                no = 0;
                ++curr;
            }
        }

        return ans;
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

// APPROACH 3
class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> cnt(26, 0);
        for (auto x : word)
            cnt[x - 97]++;

        sort(cnt.rbegin(), cnt.rend());

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 0)
                break;
            ans += ((i / 8) + 1) * cnt[i];
        }

        return ans;
    }
};