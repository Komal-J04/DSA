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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> levelQue;
        levelQue.push(root);
        int leftNodeVal = root->val;

        while (!levelQue.empty())
        {
            int currLevelSize = levelQue.size();
            int orgSize = currLevelSize;
            while (currLevelSize-- > 0) // here currLevelSize is used and then decremented
            {
                TreeNode *currNode = levelQue.front();
                levelQue.pop();
                if (orgSize - 1 == currLevelSize) // here the decremented value of currLevelSize is used
                    leftNodeVal = currNode->val;
                if (currNode->left != NULL)
                    levelQue.push(currNode->left);
                if (currNode->right != NULL)
                    levelQue.push(currNode->right);
            }
        }
        return leftNodeVal;
    }
};