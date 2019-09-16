// 515. Find Largest Value in Each Tree Row
// DescriptionHintsSubmissionsDiscussSolution
// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 

//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 

// Output: [1, 3, 9]


//基本的bfs算法，依然是level order tranverse
///每次level遍历完毕之后保存当前level traverse的最大值
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import("fmt")

func largestValues(root *TreeNode) []int {
    var ret []int
    if root == nil{
        return ret
    }
    
    //初始化只有一个root的queue
    var queue[]*TreeNode
    queue = append(queue,root)
    
    for len(queue) > 0{
        
        size := len(queue)
        cur := math.MinInt32
        
        for i:=0; i < size; i++{     
            node := queue[i]
            if cur < node.Val {
                cur = node.Val
            }
            if node.Left != nil{
                queue = append(queue,node.Left)
            }
            if node.Right != nil{
                queue = append(queue,node.Right)
            }          
        }
        queue = queue[size:]
        ret = append(ret,cur)
    }
    return ret
}
