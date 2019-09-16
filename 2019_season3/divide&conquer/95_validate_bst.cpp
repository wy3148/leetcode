// Description
// English
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// A single node tree is a BST
// Have you met this question in a real interview?  
// Example
// Example 1:

// Input:  {-1}
// Output：true
// Explanation：
// For the following binary tree（only one node）:
// 	      -1
// This is a binary search tree.
// Example 2:

// Input:  {2,1,4,#,#,3,5}
// Output: true
// For the following binary tree:
// 	  2
// 	 / \
// 	1   4
// 	   / \
// 	  3   5
// This is a binary search tree.

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
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if (root == nullptr) return true;
        TreeNode* prev = nullptr;
        
        std::stack<TreeNode* > s;
        TreeNode* n = root;
        
        //inorder traverse
        while(n != nullptr || !s.empty()){
            while(n){
                s.push(n);
                n = n->left;
            }
            TreeNode* node = s.top();s.pop();
            if (prev != nullptr){
                if (prev->val >= node->val){
                    return false;
                }
                prev = node;
            }else{
                prev = node;
            }
            n = node->right;
        }
        return true;
    }
};
