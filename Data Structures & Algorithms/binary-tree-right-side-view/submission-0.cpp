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
    using vec_int = std::vector<int>;

    void _traverseTree(const TreeNode* root, vec_int& right_view, const int level = 0)
    {
        if(!root)
            return;
        
        if((level + 1) > static_cast<int>(right_view.size()))
            right_view.emplace_back(root->val);
        
        if(root->right)
            this->_traverseTree(root->right, right_view, level + 1);
        
        if(root->left)
            this->_traverseTree(root->left, right_view, level + 1);
    }

public:
    vec_int rightSideView(TreeNode* root)
    {
        vec_int right_view;
        
        this->_traverseTree(root, right_view);

        return right_view;
    }
};
