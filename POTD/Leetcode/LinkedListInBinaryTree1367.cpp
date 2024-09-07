// https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-07

// APPROACH 1 - Check if the path starting from the current TreeNode matches the ListNode starting from head

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool checkPath(ListNode *head, TreeNode *root)
    {
        if (!root && head)
            return false;
        if (!head)
            return true;

        if (head->val == root->val)
            return checkPath(head->next, root->left) || checkPath(head->next, root->right);

        return false;
    }

    bool dfs(ListNode *head, TreeNode *root)
    {
        if (!root && head)
            return false;
        if (!head)
            return true;

        if (checkPath(head, root))
            return true;

        return dfs(head, root->left) || dfs(head, root->right);
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!head)
            return true;
        if (!root)
            return false;

        return dfs(head, root);
    }
};