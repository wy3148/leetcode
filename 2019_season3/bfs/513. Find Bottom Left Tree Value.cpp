// 513. Find Bottom Left Tree Value
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, find the leftmost value in the last row of the tree.

// Example 1:
// Input:

//     2
//    / \
//   1   3

// Output:
// 1
// Example 2: 
// Input:

//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7

// Output:
// 7
// Note: You may assume the tree (i.e., the given root node) is not NULL.


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findBottomLeftValue(root *TreeNode) int {
    if root == nil{
        return 0
    }
    
    var queue []*TreeNode
    queue = append(queue,root)
    
    var ret []int // always store the last array of the row

    for len(queue) > 0{
        size := len(queue)
        var tmp []int
        for i:= 0; i < size; i++{
            node := queue[i]
            tmp = append(tmp,node.Val)
            
            if node.Left != nil{
                queue = append(queue,node.Left)
            }
            if node.Right != nil{
                queue = append(queue,node.Right)
            }
        }
        queue = queue[size:] // pop out the visited nodes
        ret = tmp
    }
    
    if len(ret) > 0 {
        return ret[0]
    }
    return 0
}
