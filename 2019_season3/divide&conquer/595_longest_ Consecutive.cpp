
// 595. Binary Tree Longest Consecutive Sequence
// This is the problem you have done. Do you remember how to solve it?
// Description
// 中文
// English
// Given a binary tree, find the length of the longest consecutive sequence path.

// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input:
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
// Output:3
// Explanation:
// Longest consecutive sequence path is 3-4-5, so return 3.
// Example 2:

// Input:
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
// Output:2
// Explanation:
// Longest consecutive sequence path is 2-3,not 3-2-1, so return 2.


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

    int maxLen;
    
    void helper(TreeNode* root, int nextVal, int len){
        if (root == nullptr) {
            maxLen = max(maxLen,len);
            return;
        }
        
        maxLen = max(maxLen,len);
        
        if (root->left){
            if (root->left->val == nextVal){
                helper(root->left,nextVal+1, len+1);
            }else{
                helper(root->left,root->left->val +1, 1);
            }
        }
        
        if (root->right){
            if (root->right->val == nextVal){
                helper(root->right,nextVal+1, len+1);
            }else{
                helper(root->right,root->right->val +1, 1);
            }
        }
    }
    
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        maxLen = 0;
        if (root == nullptr) return maxLen;
        helper(root,root->val + 1, 1);
        return maxLen;
    }
};


//614 可以从任意一个node开始，方向也是可以往两个方向

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

    struct Result {
      int maxLen;
      int maxUpLen;
      int maxDownLen;
      Result(int l, int u, int d){
          maxLen = l;
          maxUpLen = u; //increase val + 1
          maxDownLen = d; //decrease val - 1
      }
    };
    
    Result helper(TreeNode* root){
        if (root ==nullptr){
            return Result(0,0,0);
        }
        Result l = helper(root->left);
        Result r = helper(root->right);
        
       //divide, get left subtree maxlen, and up& down len
        //get right subtree maxlen, and up and down len
        Result left = helper(root->left);
        Result right = helper(root->right);
        
        int up = 0;
        int down = 0;
        
        if(root->left && root->left->val == root->val + 1){
            up = max(up,left.maxUpLen + 1);
        }
        if (root->left && root->left->val == root->val - 1){
            down = max(down,left.maxDownLen + 1);
        }
        
        if(root->right && root->right->val == root->val + 1){
            up = max(up,right.maxUpLen + 1);
        }
        if (root->right && root->right->val == root->val - 1){
            down = max(down,right.maxDownLen + 1);
        }
        
        int curmax = max(max(left.maxLen, right.maxLen), up + down + 1);
        return Result(curmax,up,down);       
    }
    
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        // write your code here
        if (root == nullptr) return 0;
        Result r = helper(root);
        return r.maxLen;
    }
};

//619
//https://www.lintcode.com/problem/binary-tree-longest-consecutive-sequence-iii/
