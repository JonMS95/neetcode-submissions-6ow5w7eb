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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(!root)
            return "N,";
        
        return std::to_string(root->val) + "," + this->serialize(root->left) + this->serialize(root->right);
    }

    int getIntFromStr(const std::string& s)
    {
        int ret = 0;

        for(char c : s)
        {
            ret *= 10;
            ret += c - '0';
        }

        return ret;
    }

    TreeNode* traverseString(string data, int& idx)
    {
        std::string cur = "";

        while(data[idx] != ',')
        {
            cur += data[idx++];
        }
        ++idx;

        if(cur == "N")
            return nullptr;        

        TreeNode* left  = this->traverseString(data, idx);
        TreeNode* right = this->traverseString(data, idx);

        TreeNode* new_node = new TreeNode(  this->getIntFromStr(cur),
                                            left,
                                            right);

        return new_node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        int idx = 0;

        return this->traverseString(data, idx);
    }
};
