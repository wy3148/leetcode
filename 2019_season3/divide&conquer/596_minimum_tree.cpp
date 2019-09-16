// 596. Minimum Subtree
// This is the problem you have done. Do you remember how to solve it?
// Description
// English
// Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

// LintCode will print the subtree which root is your return node.
// It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input:
// {1,-5,2,1,2,-4,-5}
// Output:1
// Explanation:
// The tree is look like this:
//      1
//    /   \
//  -5     2
//  / \   /  \
// 1   2 -4  -5 
// The sum of whole tree is minimum, so return the root.
// Example 2:

// Input:
// {1}
// Output:1
// Explanation:
// The tree is look like this:
//    1
// There is one and only one subtree in the tree. So we return 1.


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

    class Result{
        public:
        TreeNode* node;
        int sum;
        Result(){
            node = nullptr;
            sum = INT_MAX;
        }
    };
    
    Result ret;
    
    int helper(TreeNode* root){
        if (!root) return 0;
        
        int val= root->val + helper(root->left) + helper(root->right);
        if (ret.sum > val){
            ret.sum= val;
            ret.node = root;
        }
        
        return val;
    }
    
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        if (root == nullptr) return nullptr;
        helper(root);
        return ret.node;
    }
};
