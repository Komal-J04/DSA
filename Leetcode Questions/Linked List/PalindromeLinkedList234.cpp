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
    string generateWord(ListNode *head)
    {
        ListNode *temp = head;
        string word = "";
        while (temp != NULL)
        {
            word += temp->val;
            temp = temp->next;
        }
        return word;
    }

    bool isPalindrome(string word)
    {
        int start = 0;
        int end = word.size() - 1;
        while (start <= end)
        {
            if (word[start] != word[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        return isPalindrome(generateWord(head));
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
    void generate(ListNode *head, vector<int> &vals)
    {
        ListNode *temp = head;
        while (temp != NULL)
        {
            vals.push_back(temp->val);
            temp = temp->next;
        }
    }

    bool isPalindrome(ListNode *head)
    {
        vector<int> vals;
        generate(head, vals);

        int start = 0, end = vals.size() - 1;

        while (start <= end)
        {
            if (vals[start] != vals[end])
                return false;
            start++;
            end--;
        }

        return true;
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

// APPROACH 3 - recursive   TC = O(N)     SC = O(N)
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
    ListNode *curr;

public:
    Solution() : curr(NULL){};

    bool helper(ListNode *head)
    {
        if (head == NULL)
            return true;
        bool ans = helper(head->next) && head->val == curr->val;
        curr = curr->next;
        return ans;
    }
    bool isPalindrome(ListNode *head)
    {
        curr = head;
        return helper(head);
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

// APPROACH 4 - using stack
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
    bool isPalindrome(ListNode *head)
    {
        stack<int> s;
        ListNode *temp = head;
        while (temp != NULL)
        {
            s.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL && temp->val == s.top())
        {
            s.pop();
            temp = temp->next;
        }

        return temp == NULL;
    }
};