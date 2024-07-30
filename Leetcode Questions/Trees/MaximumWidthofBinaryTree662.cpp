// APPROACH 1

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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        long long width = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int sz = q.size();
            long long maxi, mini, minInd = q.front().second;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front().first;
                long long index = q.front().second - minInd;
                q.pop();
                if (i == 0)
                    mini = index;
                if (i == (sz - 1))
                    maxi = index;
                if (curr->left)
                    q.push({curr->left, (2 * index) + 1});
                if (curr->right)
                    q.push({curr->right, (2 * index) + 2});
            }
            width = max(width, maxi - mini + 1);
        }
        return (int)width;
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

// APPROACH 2 - accessing last element of the queue

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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        long long width = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int sz = q.size();
            long long minInd = q.front().second;
            width = max(width, q.back().second - q.front().second + 1);
            for (int i = 0; i < sz; i++)
            {
                TreeNode *curr = q.front().first;
                long long index = q.front().second - minInd;
                q.pop();
                if (curr->left)
                    q.push({curr->left, (2 * index) + 1});
                if (curr->right)
                    q.push({curr->right, (2 * index) + 2});
            }
        }
        return (int)width;
    }
};