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
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // If (p is null and q is not null) or (p is not null and q is null).
        if(p && !q || !p && q)
            return false;
        
        // If both are null, then both nodes are equal.
        if(!p && !q)
            return true;
        
        // If both are non-null, then whether their values are different.
        if(p->val != q->val)
            return false;
        
        // Having reached this point, both values are equal for p and q. Now check if the
        // same goes for their pending nodes.
        return (this->isSameTree(p->left, q->left) && this->isSameTree(p->right, q->right));
    }
};
