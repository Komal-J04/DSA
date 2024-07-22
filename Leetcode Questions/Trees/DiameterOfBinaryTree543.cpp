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
    int calcDiameter(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;
        int left = calcDiameter(root->left, diameter);
        int right = calcDiameter(root->right, diameter);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        calcDiameter(root, diameter);
        return diameter;
    }
};