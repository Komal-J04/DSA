// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?envType=daily-question&envId=2024-05-16

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
    bool evaluateTree(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return root->val == 0 ? false : true;

        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        if (root->val == 2)
            return leftVal | rightVal;
        return leftVal & rightVal; // this will be executed only when the above is false which means value of the node=3
    }
};