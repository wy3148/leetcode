98. Validate Binary Search Tree



//错误！！！！！ 
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr) return true;
        if (root->left && root->left->val >= root->val) return false;
        if (root->right && root->right->val <= root->val) return false;
        
        //递归不能比较到  root， 和子节点的子节点的值
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
};


// 应该inorder的判断数组是否是升序！！！


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var data []int


func inorder(root* TreeNode) bool{
    if root == nil {
        return true
    }
    l := inorder(root.Left)
    if l == false{
        return false
    }
    if len(data) > 0 && data[len(data) - 1] >= root.Val{
        return false
    }
    data = append(data,root.Val)
    return inorder(root.Right)
}
func isValidBST(root *TreeNode) bool {
    data = make([]int, 0) // this is for leetcode compability 
    return inorder(root) 
}