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
private:
    void traverseTree(TreeNode* root, int& max_depth, int cur_depth = 1)
    {
        if(!root)
            return;

        if(max_depth < cur_depth)
            max_depth = cur_depth;
        
        if(root->left)
            this->traverseTree(root->left, max_depth, cur_depth + 1);
        
        if(root->right)
            this->traverseTree(root->right, max_depth, cur_depth + 1);
    }

public:
    int maxDepth(TreeNode* root)
    {
        int ret = 0;

        this->traverseTree(root, ret);

        return ret;
    }
};
