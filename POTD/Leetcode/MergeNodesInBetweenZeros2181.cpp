// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04

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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ans = new ListNode(-1);
        ListNode *temp2 = ans;
        ListNode *temp = head->next;
        int s = 0;
        while (temp)
        {
            while (temp && temp->val != 0)
            {
                s = s + temp->val;
                temp = temp->next;
            }
            temp2->next = new ListNode(s);
            temp2 = temp2->next;
            s = 0;
            temp = temp->next;
        }
        return ans->next;
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

// APPROACH 2 - modifying the original linked list (in place)
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *toModify = head->next;
        ListNode *temp = head->next;

        while (temp)
        {
            int s = 0;
            while (temp->val != 0)
            {
                s = s + temp->val;
                temp = temp->next;
            }
            toModify->val = s;
            temp = temp->next;
            toModify->next = temp;
            toModify = toModify->next;
        }

        return head->next;
    }
};