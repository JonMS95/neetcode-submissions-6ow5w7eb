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
    void _inorderTraversal(const TreeNode* root, std::vector<int>& tree_values)
    {
        if(!root)
            return;

        if(root->left)
            this->_inorderTraversal(root->left, tree_values);

        tree_values.emplace_back(root->val);

        if(root->right)
            this->_inorderTraversal(root->right, tree_values);
    }

public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> ret;

        this->_inorderTraversal(root, ret);

        return ret;
    }
};