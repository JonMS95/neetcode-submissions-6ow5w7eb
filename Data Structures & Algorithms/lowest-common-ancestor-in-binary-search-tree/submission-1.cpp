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
    typedef enum
    {
        LOWER   = 0,
        GREATER = 1,
        EQUAL   = 2,
    } NODE_STATUS;

    NODE_STATUS getNodeStatus(TreeNode* root, TreeNode* target)
    {
        if(target->val < root->val)
            return LOWER;
        
        if(target->val > root->val)
            return GREATER;
        
        return EQUAL;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root || !p || !q)
            return nullptr;

        // Compare p and q values with current node.
        NODE_STATUS p_status = this->getNodeStatus(root, p);
        NODE_STATUS q_status = this->getNodeStatus(root, q);

        if((p_status != q_status) || (p_status == EQUAL && q_status == EQUAL))
            return root;
        
        if(p_status == LOWER)
            return this->lowestCommonAncestor(root->left, p, q);
        else // p_status == GREATER
            return this->lowestCommonAncestor(root->right, p, q);
        
        return nullptr;
    }
};
