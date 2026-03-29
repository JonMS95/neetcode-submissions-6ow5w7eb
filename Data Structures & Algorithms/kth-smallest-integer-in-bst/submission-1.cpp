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
    void getVectorFromTree(TreeNode* root, std::vector<int>& vec, const int k)
    {
        if(!root)
            return;
        
        if(root->left)
            this->getVectorFromTree(root->left, vec, k);

        if(vec.size() < k)
            vec.emplace_back(root->val);
        else
            return;

        if(root->right)
            this->getVectorFromTree(root->right, vec, k);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        std::vector<int> vec;
        this->getVectorFromTree(root, vec, k);
        return vec[vec.size() - 1];
    }
};
