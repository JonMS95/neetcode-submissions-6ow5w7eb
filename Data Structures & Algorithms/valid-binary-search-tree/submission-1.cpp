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
    void getVectorFromInOrderTraversal(TreeNode* root, std::vector<int>& vec)
    {
        if(!root)
            return;

        if(root->left)
            this->getVectorFromInOrderTraversal(root->left, vec);
        
        vec.emplace_back(root->val);

        if(root->right)
            this->getVectorFromInOrderTraversal(root->right, vec);
    }

    bool checkIfVectorIsOrdered(std::vector<int>& vec)
    {
        for(int i = 0; i < (static_cast<int>(vec.size() - 1)); i++)
            if(vec[i] >= vec[i + 1])
                return false;
        
        return true;
    }

public:
    bool isValidBST(TreeNode* root)
    {
        std::vector<int> vec;
        this->getVectorFromInOrderTraversal(root, vec);
        return this->checkIfVectorIsOrdered(vec);
    }
};
