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
    int path(TreeNode *root, int &maxi)
    {
        if (!root)
            return 0;
        int left = max(0, path(root->left, maxi));
        int right = max(0, path(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode *root)
    {
        // if(!root->left && !root->right) return root->val;
        int maxi = INT_MIN;
        path(root, maxi);
        return maxi;
    }
};