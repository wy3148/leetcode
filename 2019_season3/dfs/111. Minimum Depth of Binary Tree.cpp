// 111. Minimum Depth of Binary Tree
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example:

// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.




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
    int depth;
    
    void helper(TreeNode* root, int d){
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr){
            depth = min(depth, d + 1);
        }
        helper(root->left,d + 1);
        helper(root->right, d + 1);
    }
    
    int minDepth(TreeNode* root) {
        if (root ==nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        depth = INT_MAX;
        helper(root,0);
        return depth;
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
    int depth(TreeNode* root){
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
            int l =INT_MAX; int r = INT_MAX;
            if (root->left){
                l = depth(root->left);
            }
            if (root->right){
                r = depth(root->right);
            }
        
        return min(l,r ) + 1;
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return depth(root);
    }
};