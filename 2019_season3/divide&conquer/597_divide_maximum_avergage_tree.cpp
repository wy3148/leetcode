// Back
// 597. Subtree with Maximum Average
// Description
// 中文
// English
// Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

// LintCode will print the subtree which root is your return node.
// It's guaranteed that there is only one subtree with maximum average.

// Have you met this question in a real interview?  
// Example
// Example 1

// Input：
// {1,-5,11,1,2,4,-2}
// Output：11
// Explanation:
// The tree is look like this:
//      1
//    /   \
//  -5     11
//  / \   /  \
// 1   2 4    -2 
// The average of subtree of 11 is 4.3333, is the maximun.
// Example 2

// Input：
// {1,-5,11}
// Output：11
// Explanation:
//      1
//    /   \
//  -5     11
// The average of subtree of 1,-5,11 is 2.333,-5,11. So the subtree of 11 is the maximun

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
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    
    //定义一个辅助class，数据结构
    struct Result{
        TreeNode* node;
        int sum;
        int size;
        Result(){
            node == nullptr;
            int sum = INT_MIN;
            int size = INT_MAX;
        }
        Result(TreeNode* n , int s, int l){
            node = n;
            sum = s;
            size = l;
        }
    };
    
    Result finalR;
    
    Result helper(TreeNode* root){
        if (root == nullptr){
            return Result(nullptr,0,0);
        }
        
        Result l = helper(root->left);
        Result r = helper(root->right);
        
        double avg = double(root->val +l.sum + r.sum) / double(l.size +r.size + 1);
        
        //meaning, finaR is not caculated yet
        if (finalR.size == 0){
            finalR =  Result(root,root->val + l.sum + r.sum,l.size + r.size + 1);
        }else{
            double current = double(finalR.sum)/double(finalR.size);
               
            //update the final result
            if (current < avg) {
                finalR = Result(root,root->val + l.sum + r.sum,l.size + r.size + 1);
            }
        }
        
        return Result(root,root->val + r.sum +l.sum,l.size + r.size + 1);
    }
    
    TreeNode * findSubtree2(TreeNode * root) {
        //divide&&conquer,以每一个node为root的平均值更新
        if (root == nullptr) return root;
        finalR = Result(nullptr,0,0);
        helper(root);
        return finalR.node;
    }
};
