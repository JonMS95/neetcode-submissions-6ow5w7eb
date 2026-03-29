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
For each node: if leaf node, then simply return maximum with zero. Otherwise, compute maximums for pending
nodes. Then, pick the maximum among those. Afterwards, add maximum to node value and pick the maximum again
between 0 and computed value.

For each visited node, do also the following: compute the sum of all three components (left subtree, right
subtree and self) and update maximum global value if needed.
*/

class Solution {
private:
    int _dfs(const TreeNode* root, int& max)
    {
        if(!root)
            throw std::runtime_error("Null node reached");

        int lss = 0, rss = 0; // left / right subtree sum.
        int cur, ret;

        if(root->left)
            lss = this->_dfs(root->left, max);
        
        if(root->right)
            rss = this->_dfs(root->right, max);

        std::cout << "Node: " << root->val << std::endl;
        std::cout << "LSS: " << lss << std::endl;
        std::cout << "RSS: " << rss << std::endl;
        std::cout << std::endl;

        cur = lss + rss + root->val;

        if(cur > max)
            max = cur;
        
        return std::max(0, root->val + std::max(lss, rss));
    }

public:
    int maxPathSum(TreeNode* root)
    {
        int ret = INT_MIN;

        this->_dfs(root, ret);
    
        return ret;
    }
};
