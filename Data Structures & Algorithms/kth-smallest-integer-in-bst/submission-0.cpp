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

class Solution
{
private:
    void getVectorFromTree(TreeNode* root, std::vector<int>& vec)
    {
        if(!root)
            return;
        
        if(root->left)
            this->getVectorFromTree(root->left, vec);
        
        vec.emplace_back(root->val);

        if(root->right)
            this->getVectorFromTree(root->right, vec);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        std::vector<int> vec;
        this->getVectorFromTree(root, vec);
        return vec[k - 1];
    }
};
