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
    void _traversal(const TreeNode* root, std::vector<int>& vec)
    {
        if(!root)
            throw std::runtime_error("Reached null node!");

        // As soon as the node is reached, push it to the vector.
        vec.emplace_back(root->val);

        // Afterwards, explore pending nodes (if any): left one first, then the right node.
        if(root->left)
            this->_traversal(root->left, vec);
        
        if(root->right)
            this->_traversal(root->right, vec);
    }

public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> ret;

        if(!root)
            return ret;

        this->_traversal(root, ret);

        return ret;
    }
};