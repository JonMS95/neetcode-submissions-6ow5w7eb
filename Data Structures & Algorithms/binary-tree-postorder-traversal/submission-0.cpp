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
Go through pending nodes first, push current node to vector afterwards.
*/

class Solution
{
private:
    void _traversal(const TreeNode* root, std::vector<int>& vec)
    {
        if(!root)
            throw std::runtime_error("Reached null node!");
        
        if(root->left)
            this->_traversal(root->left, vec);
        
        if(root->right)
            this->_traversal(root->right, vec);
        
        vec.emplace_back(root->val);
    }

public:
    std::vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> ret;

        if(!root)
            return ret;

        this->_traversal(root, ret);

        return ret;
    }
};