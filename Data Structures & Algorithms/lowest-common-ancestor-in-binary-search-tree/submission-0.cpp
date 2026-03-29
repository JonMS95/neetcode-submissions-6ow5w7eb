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
    const int left  = 0;
    const int right = 1;
    const int same  = 2;

    void getPathToNode(TreeNode* root, TreeNode* target, std::vector<TreeNode*>& path)
    {
        if(!root || !target)
            return;
        
        if(root->val == target->val)
        {
            path.emplace_back(root);
            return;
        }

        if(target->val < root->val && root->left)
        {
            path.emplace_back(root);
            this->getPathToNode(root->left, target, path);
        }
        else
        {
            path.emplace_back(root);
            this->getPathToNode(root->right, target, path);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::vector<TreeNode*> p_path, q_path;

        this->getPathToNode(root, p, p_path);
        this->getPathToNode(root, q, q_path);

        TreeNode* ret = nullptr;

        for(int i = 0; i < static_cast<int>(std::min(p_path.size(), q_path.size())); i++)
        {
            if(p_path[i] != q_path[i])
                break;
            
            ret = p_path[i];
        }
            

        return ret;
    }
};
