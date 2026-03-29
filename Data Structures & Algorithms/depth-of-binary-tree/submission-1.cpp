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
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;

        int left_depth  = 0;
        int right_depth = 0;

        if(root->left)
            left_depth = this->maxDepth(root->left);
        
        if(root->right)
            right_depth = this->maxDepth(root->right);
        
        return 1 + std::max(left_depth, right_depth);
    }
};
