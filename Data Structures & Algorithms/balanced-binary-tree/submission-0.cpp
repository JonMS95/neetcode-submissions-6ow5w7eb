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
Two problems here:
1-Get tree depth starting from a given node.
2-Check whether each subtree (for a given node) has a height that differs at most by 1.
*/

class Solution {
private:
    int _getDepth(const TreeNode* root)
    {
        if(!root)
            return 0;
        
        int lsd = 0;
        int rsd = 0;

        if(root->left)
            lsd = this->_getDepth(root->left);
        
        if(root->right)
            rsd = this->_getDepth(root->right);

        if(lsd < 0 || rsd < 0 || std::abs(lsd - rsd) > 1)
            return -1;

        return (1 + (std::max(lsd, rsd)));
    }

public:
    bool isBalanced(TreeNode* root)
    {
        if(this->_getDepth(root) < 0)
            return false;
        else
            return true;
    }
};
