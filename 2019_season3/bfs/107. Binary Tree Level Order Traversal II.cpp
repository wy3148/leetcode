// 107. Binary Tree Level Order Traversal II
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //正常level tranverse 然后翻转一下就可
        vector<vector<int>> ret;
        if (!root) return ret;
        
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> tmp;
            
            for (int i = 0; i < size; i++){
                auto n = q.front(); q.pop();
                tmp.push_back(n->val);    
                
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            ret.push_back(tmp);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
