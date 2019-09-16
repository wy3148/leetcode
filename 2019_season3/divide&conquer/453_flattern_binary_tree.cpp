// Back
// 453. Flatten Binary Tree to Linked List
// Description
// 中文
// English
// Flatten a binary tree to a fake "linked list" in pre-order traversal.

// Here we use the right pointer in TreeNode as the next pointer in ListNode.

// Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input:{1,2,5,3,4,#,6}
// Output：{1,#,2,#,3,#,4,#,5,#,6}
// Explanation：
//      1
//     / \
//    2   5
//   / \   \
//  3   4   6

// 1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6
// Example 2:

// Input:{1}
// Output:{1}
// Explanation：
//          1
//          1
// Challenge
// Do it in-place without any extra memory.

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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    
    void preOrder(std::vector<TreeNode*>& ret, TreeNode* root){
        if (root == nullptr) return;
        ret.push_back(root);
        preOrder(ret,root->left);
        preOrder(ret,root->right);
    }
    
    void flatten(TreeNode * root) {
        // write your code here
        if (root == nullptr) return;
        vector<TreeNode*> ret;
        preOrder(ret,root);
        TreeNode* prev = root;
        for (int i  = 1; i < ret.size(); i++){
            prev->left = nullptr;
            prev->right = ret[i];
            prev = ret[i];
        }
        prev->right = nullptr;
    }
};


//A better solution

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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        // write your code here
        if (root == nullptr) return;
        
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* prev = nullptr;
        while(!s.empty()){
            auto n = s.top(); s.pop();
            if (n->right){
                s.push(n->right);
            }
            
            if(n->left){
                s.push(n->left);
            }
            
            if (prev == nullptr){
                prev = n;
            }else{
                prev->right = n;
                prev->left = nullptr;
                prev = n;
            }
        }
    }
};