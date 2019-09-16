// 111. Minimum Depth of Binary Tree

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        if (root->left == nullptr && root->right == nullptr){
            return 1;
        }
        
        if (root->left && root->right){
            int l = minDepth(root->left);
            int r = minDepth(root->right);
            return 1 + min(l,r);
        }else if (root->left){
            return 1 + minDepth(root->left);
        }
        return 1 + minDepth(root->right);
    }
};

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        if (root->left == nullptr && root->right == nullptr){
            return 1;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* n = q.front(); q.pop();
                if (n->left == nullptr && n->right == nullptr){
                    return depth;
                }
                if (n->left){
                    q.push(n->left);
                }
                if (n->right){
                    q.push(n->right);
                }
            }
        }
        return depth;
    }
};