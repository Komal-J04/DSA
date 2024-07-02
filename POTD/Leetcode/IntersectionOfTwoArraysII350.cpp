// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int max1 = *max_element(nums1.begin(), nums1.end());
        int max2 = *max_element(nums2.begin(), nums2.end());
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        vector<int> count1(max1 + 1);
        vector<int> count2(max2 + 1);

        for (int i = 0; i < sz1; i++)
            count1[nums1[i]]++;
        for (int i = 0; i < sz2; i++)
            count2[nums2[i]]++;

        int x = (max1 < max2) ? max1 : max2;

        for (int i = 0; i <= x; i++)
        {
            int p = (count1[i] < count2[i]) ? count1[i] : count2[i];
            while (p > 0)
            {
                ans.push_back(i);
                p--;
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

// APPROACH 2

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int sz1 = nums1.size();
        int sz2 = nums2.size();

        int i = 0, j = 0;
        while (i < sz1 && j < sz2)
        {
            if (nums1[i] == nums2[j])
            {
                while (i < sz1 && j < sz2 && nums1[i] == nums2[j])
                {
                    ans.push_back(nums1[i]);
                    i++;
                    j++;
                }
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
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

// APPROACH 3 - using map
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        for (int i = 0; i < sz1; i++)
            mp[nums1[i]]++;

        for (int i = 0; i < sz2; i++)
        {
            if ((mp.find(nums2[i]) != mp.end()) && (mp[nums2[i]] != 0))
            {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }

        return ans;
    }
};