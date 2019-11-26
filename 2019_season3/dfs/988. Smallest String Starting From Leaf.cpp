

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
    
    //max heap is by default, we need to min heap 
    priority_queue<string,vector<string>, std::greater<string> > q;
    
    //all path to leaves, and reverse
    void paths(string& cur,TreeNode* root){
        if (!root) return;
        cur.push_back('a' + root->val);
        
        if (root->left == nullptr && root->right == nullptr){
            string tmp(cur);
            reverse(tmp.begin(),tmp.end());
            q.push(tmp);
            return;
        }
        
        if (root->left){
            paths(cur,root->left);
            cur.pop_back();
        }
        
        if(root->right){
            paths(cur,root->right);
            cur.pop_back();
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        string cur;
        paths(cur,root);
        return q.top();
    }
};
