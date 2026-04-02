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

/*
Check pending nodes. If those are pending nodes with target value, remove them (parent node points
at null afterwards). Current node can be leaf node with target value afterwards as well too.
*/

class Solution
{
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        // Does current node have pending node? If so, inspect them.
        if(root->left)
            root->left = this->removeLeafNodes(root->left, target);
        
        // Do it for both nodes.
        if(root->right)
            root->right = this->removeLeafNodes(root->right, target);

        // Is current node a leaf? If so, does it have the target value?
        if(!root->left && !root->right && root->val == target)
            root = nullptr;
        
        return root;
    }
};