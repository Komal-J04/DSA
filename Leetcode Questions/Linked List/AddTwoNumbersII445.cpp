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
    void reverse(ListNode *&head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward;
        while (curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }

    ListNode *add(ListNode *head1, ListNode *head2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        int sum = 0, carry = 0;

        while (temp1 || temp2 || carry)
        {
            sum = (temp1 ? temp1->val : 0) + (temp2 ? temp2->val : 0) + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            curr = curr->next;

            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        return head->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        reverse(l1);
        reverse(l2);
        ListNode *newHead = add(l1, l2);
        reverse(newHead);
        return newHead;
    }
};