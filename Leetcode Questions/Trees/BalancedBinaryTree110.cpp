// APPROACH 1 - NAIVE APPROACH

// TC - O(N^2) [finding height and checking for each node]

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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if (abs(lHeight - rHeight) > 1)
            return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right)
            return false;
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

// APPROACH 2
// TC - O(N)

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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        if ((l == -1) || (r == -1))
            return -1;
        if (abs(l - r) > 1)
            return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (height(root) == -1)
            return false;
        return true;
    }
};