// Description
// English
// Given a binary tree, find the maximum path sum.

// The path may start and end at any node in the tree.

// Have you met this question in a real interview?  
// Example
// Example 1:
// 	Input:  For the following binary tree（only one node）:
// 	2
// 	Output：2
	
// Example 2:
// 	Input:  For the following binary tree:

//       1
//      / \
//     2   3
		
// 	Output: 6

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
    
    int result;

    int helper(TreeNode* root){
        if (root == nullptr) return 0;
        
        int l = helper(root->left);
        int r = helper(root->right);
        
        int sum = root->val;
        if (l > 0) {
            sum += l;
        }
        if (r > 0){
            sum += r;
        }
        
        //更新最终的结果
        result = max(result,sum);
        
        //当前的path，如果是负数就不用加，否则选择一边
        //left side, or right side
        return max(0, max(l,r) + root->val);
    }
    
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        result = INT_MIN;
        helper(root);
        return result;
    }
};
