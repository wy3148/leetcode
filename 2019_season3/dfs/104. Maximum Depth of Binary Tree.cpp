// 104. Maximum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func max(a, b int ) int {
    if a >= b {
        return a
    }
    return b
}

func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    l := maxDepth(root.Left)
    r := maxDepth(root.Right)
    return max(l , r) + 1 
}
