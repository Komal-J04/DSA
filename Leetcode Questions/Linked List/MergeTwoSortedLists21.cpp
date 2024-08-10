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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head = NULL;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *temp = head;
        if (temp1->val <= temp2->val)
        {
            head = temp1;
            temp1 = temp1->next;
            temp = head;
        }
        else
        {
            head = temp2;
            temp2 = temp2->next;
            temp = head;
        }

        while (temp1 && temp2)
        {
            if (temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
        }

        while (temp1)
        {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }

        while (temp2)
        {
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }

        return head;
    }
};