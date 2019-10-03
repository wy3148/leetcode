// 257. Binary Tree Paths
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3



/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import "strconv"

func dfs(root *TreeNode,ret *[]string, str string){
    if root == nil {
        return
    }
    if len(str) == 0 {
        (str) = strconv.Itoa(root.Val)
    }else{
        (str) += "->" + strconv.Itoa(root.Val)
    }
    
    if root.Left == nil && root.Right == nil {
        (*ret) = append(*ret,str)
        return
    }
    
    dfs(root.Left,ret,str)
    dfs(root.Right,ret, str)
}

func binaryTreePaths(root *TreeNode) []string {    
    var cur string
    var ret []string
    dfs(root,&ret,cur)
    return ret
}