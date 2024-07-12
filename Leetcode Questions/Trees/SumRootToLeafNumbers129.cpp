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
    int helper(TreeNode *root, int x)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return (x * 10) + root->val;

        x = (x * 10) + root->val;
        return helper(root->left, x) + helper(root->right, x);
    }

    int sumNumbers(TreeNode *root)
    {
        return helper(root, 0);
    }
};