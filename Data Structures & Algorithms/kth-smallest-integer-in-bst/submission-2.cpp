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
    void _traverseTree( const TreeNode* root                                            ,
                        const int k                                                     ,
                        std::priority_queue<int, std::vector<int>, std::less<int>>& heap  )
    {
        if(!root)
            return;
        
        heap.push(root->val);

        while(heap.size() > k)
            heap.pop();
        
        if(root->left)
            _traverseTree(root->left, k, heap);
        
        if(root->right)
            _traverseTree(root->right, k, heap);
    }

public:
    int kthSmallest(TreeNode* root, int k)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> min_heap;

        _traverseTree(root, k, min_heap);

        return min_heap.top();
    }
};
