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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr)
        {
            bool fnd = false;
            while (curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                fnd = true;
            }
            if (fnd)
                prev->next = curr->next;
            else
                prev = prev->next;

            curr = curr->next;
        }

        return dummy->next;
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

// APPROACH 2 - without dummy
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        while (head)
        {
            ListNode *temp = head->next;
            if (temp == NULL || (temp && temp->val != head->val))
                break;
            while (temp && temp->val == head->val)
                temp = temp->next;
            head = temp;
        }
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr)
        {
            bool fnd = false;
            while (curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                fnd = true;
            }
            if (fnd)
                prev->next = curr->next;
            else
                prev = prev->next;

            curr = curr->next;
        }

        return head;
    }
};