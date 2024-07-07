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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            s.insert(nums[i]);

        ListNode *temp = head;
        int components = 0;

        while (temp)
        {
            if (s.find(temp->val) != s.end())
            {
                while (temp && s.find(temp->val) != s.end())
                {
                    temp = temp->next;
                }
                components++;
            }
            else
                temp = temp->next;
        }
        return components;
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

// APPROACH 2 - if the list is sorted, following approach can be used as well
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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        ListNode *temp = head;
        int i = 0, n = nums.size();
        int components = 0;
        while (temp && i < n)
        {
            if (temp->val == nums[i])
            {
                while (temp && i < n && temp->val == nums[i])
                {
                    temp = temp->next;
                    i++;
                }
                components++;
            }
            else if (temp->val < nums[i])
                temp = temp->next;
            else
                i++;
        }
        return components;
    }
};