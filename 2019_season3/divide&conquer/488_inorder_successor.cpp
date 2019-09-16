
// 448. Inorder Successor in BST
// This is the problem you have done. Do you remember how to solve it?
// Description
// 中文
// English
// Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

// If the given node has no in-order successor in the tree, return null.

// It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input: {1,#,2}, node with value 1
// Output: 2
// Explanation:
//   1
//    \
//     2
// Example 2:

// Input: {2,1,3}, node with value 1
// Output: 2
// Explanation: 
//     2
//    / \
//   1   3

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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        TreeNode* prev = nullptr;
        
        //inorder: left, root , right
        stack<TreeNode*> s;
        TreeNode* n = root;
        
        while(n || !s.empty()){
            
            while(n){
                s.push(n);
                n = n->left;
            }
        
            TreeNode* node = s.top(); s.pop();
            if(prev == p){
                return node;
            }else{
                prev = node;
            }
            
            //if the node has right subtree
            if (node->right){
                n = node->right;
            }
        }
        return nullptr;
    }
};
