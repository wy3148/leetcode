


// 113. Path Sum II
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
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
    
    vector<vector<int>> ret;

    void dfs(vector<int>& cur, int sum, TreeNode* node, int given){
        if (!node) return;
        sum += node->val;
        cur.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr){
            if (sum == given){
                ret.push_back(cur);
            }
            return;
        }
        
        if (node->left){
            dfs(cur,sum,node->left,given);
            cur.pop_back();
        }
        
        if (node->right){
            dfs(cur,sum,node->right,given);
            cur.pop_back();           
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        dfs(tmp,0,root,sum);
        return ret;
    }
};
