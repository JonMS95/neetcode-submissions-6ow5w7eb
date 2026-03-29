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
    void traverseTree(TreeNode* root)
    {
        if(!root)
            return;

        TreeNode* aux = root->left;
        root->left = root->right;
        root->right = aux;

        if(root->left)
            this->traverseTree(root->left);
        
        if(root->right)
            this->traverseTree(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root)
    {
        this->traverseTree(root);

        return root;
    }
};
