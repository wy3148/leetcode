// 110. Balanced Binary Tree
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example 1:

// Given the following tree [3,9,20,null,null,15,7]:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.

// Example 2:

// Given the following tree [1,2,2,3,3,null,null,4,4]:

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

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
       return max(depth(root->left), depth(root->right)) + 1;
    }
        
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int l = depth(root->left); 
        int r = depth(root->right);
        if (abs(l - r) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};



//记录node的深度

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
    
    //dfs ,记录每个结点的深度
    int depth(TreeNode* root){
        if (root == nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        
        if (l == -1 || r == -1 || abs(l -r ) > 1){
            return -1;
        }
        return max(l,r ) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};
