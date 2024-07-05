// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2024-07-05

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int cnt = 1;
        ListNode *prev = head;
        ListNode *curr = head->next;
        set<int> s;
        while (curr->next)
        {
            if (((curr->val > prev->val) && (curr->val > curr->next->val)) || (((curr->val < prev->val) && (curr->val < curr->next->val))))
                s.insert(cnt);

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (s.size() < 2)
            return {-1, -1};

        vector<int> ans;
        int mini = INT_MAX;

        for (auto it = s.begin(); next(it) != s.end(); it++)
        {
            if ((*next(it) - *it) < mini)
                mini = *next(it) - *it;
        }

        ans.push_back(mini);
        ans.push_back(*s.rbegin() - *s.begin());

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

// APPROACH 2 - using vector

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int cnt = 1;
        ListNode *prev = head;
        ListNode *curr = head->next;
        vector<int> s;
        while (curr->next)
        {
            if (((curr->val > prev->val) && (curr->val > curr->next->val)) || (((curr->val < prev->val) && (curr->val < curr->next->val))))
                s.push_back(cnt);

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (s.size() < 2)
            return {-1, -1};

        vector<int> ans;
        int mini = INT_MAX;

        for (int i = 0; i < (s.size() - 1); i++)
        {
            if ((s[i + 1] - s[i]) < mini)
                mini = s[i + 1] - s[i];
        }

        ans.push_back(mini);
        ans.push_back(s[s.size() - 1] - s[0]);

        return ans;
    }
};