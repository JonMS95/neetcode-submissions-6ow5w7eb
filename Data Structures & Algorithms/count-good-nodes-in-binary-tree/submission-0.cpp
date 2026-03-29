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

class Solution {
private:
    void _traverseTree(const TreeNode* root, int max, int& gn)
    {
        if(root->val >= max)
        {
            max = root->val;
            ++gn;
        }
        
        if(root->left)
            this->_traverseTree(root->left, max, gn);
        
        if(root->right)
            this->_traverseTree(root->right, max, gn);
    }

public:
    int goodNodes(TreeNode* root)
    {
        int good_nodes = 0;
        this->_traverseTree(root, root->val - 1, good_nodes);
        return good_nodes;
    }
};
