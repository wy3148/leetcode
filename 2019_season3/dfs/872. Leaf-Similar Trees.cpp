

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void leaves(TreeNode* root, vector<int>& data){
        if (root == nullptr) return;
        
        if (root->left == nullptr && root->right == nullptr) data.push_back(root->val);
        
        leaves(root->left, data);
        leaves(root->right, data);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> data1;
        vector<int> data2;
        
        leaves(root1, data1);
        leaves(root2, data2);
        if (data1.size( ) != data2.size()) return false;
        
        for(int i = 0; i < data1.size();i++){
            if (data1[i] != data2[i]) return false;
        }
        return true;
    }
};
