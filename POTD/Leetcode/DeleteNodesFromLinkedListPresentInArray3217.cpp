// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/submissions/1380634537/?envType=daily-question&envId=2024-09-06

// APPROACH 1 - TLE FOR LARGE TEST CASES
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        ListNode *forward;

        while (head && (find(nums.begin(), nums.end(), head->val) != nums.end()))
        {
            forward = head->next;
            delete head;
            head = forward;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            if (find(nums.begin(), nums.end(), curr->val) != nums.end())
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
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

// APPROACH 2 - UNORDERED_SET OFFERS LESSER TIME COMPLEXITY THAN ORDERED_SET
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        ListNode *forward;
        unordered_set<int> s(nums.begin(), nums.end());

        while (head && (s.find(head->val) != s.end()))
        {
            forward = head->next;
            delete head;
            head = forward;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            if (s.find(curr->val) != s.end())
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
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

// APPROACH 3 - MAKING A NEW LL
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode *newHead = new ListNode(-1);
        ListNode *temp = newHead;
        while (head)
        {
            if (s.find(head->val) == s.end())
            {
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            head = head->next;
        }
        return newHead->next;
    }
};