
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
    
    unordered_set<int> needDel;
    vector<TreeNode*> ret;
    
    void path(TreeNode* parent, TreeNode* node){
        if (!node){
            return;
        }
        if (needDel.find(node->val) == needDel.end()){   
            if (parent == nullptr){
                ret.push_back(node);
            }
            path(node,node->left);
            path(node,node->right);
        }else{
            
            //we need to remove the deleted node,so set it parente left or right child node as nullptr now
            if (parent && parent->left == node) parent->left = nullptr;
            if (parent && parent->right == node) parent->right = nullptr;
            
            if (node->left){
                path(nullptr, node->left);
            }
            
            if (node->right){
                path(nullptr,node->right);
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto& v : to_delete){
            needDel.insert(v);
        }
        path(nullptr,root);
        return ret;
    }
};
