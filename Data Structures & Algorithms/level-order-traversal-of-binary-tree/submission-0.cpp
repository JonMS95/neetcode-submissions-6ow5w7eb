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
    using mat_int = std::vector<std::vector<int>>;

    void treeTraversal(const TreeNode* root, mat_int& level_values, const int level = 0)
    {
        if(!root)
            return;

        if((level + 1) > static_cast<int>(level_values.size()))
            level_values.push_back({root->val});
        else
            level_values[level].emplace_back(root->val);
        
        if(root->left)
            this->treeTraversal(root->left, level_values, level + 1);
        
        if(root->right)
            this->treeTraversal(root->right, level_values, level + 1);
    }

public:
    mat_int levelOrder(TreeNode* root)
    {
        mat_int ret;
        this->treeTraversal(root, ret);
        return ret;
    }
};
