// Description
// 中文
// English
// Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

// Have you met this question in a real interview?  
// Example
// Example1
// Input: {1,2,3,4,5}
// Output: [[4, 5, 3], [2], [1]].
// Explanation:

//     1
//    / \
//   2   3
//  / \     
// 4   5    
// Example2
// Input: {1,2,3,4}
// Output: [[4, 3], [2], [1]].
// Explanation:

//     1
//    / \
//   2   3
//  /
// 4 
// Related Problems


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:

    int maxDepth;
    
    //depth, and nodes map
    unordered_map<int, vector<int> > depth;
    
    int dfs(TreeNode* node){
        if (!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        
        int d = max(l,r) + 1;
        maxDepth = max(maxDepth,d);
        depth[d].push_back(node->val);
        return d;
    }
    
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        maxDepth = 0;
        dfs(root);
        vector<vector<int>> ret;
        for(int i = 1; i <= maxDepth; i++){
            ret.push_back(depth[i]);
        }
        return ret;
    }
};
