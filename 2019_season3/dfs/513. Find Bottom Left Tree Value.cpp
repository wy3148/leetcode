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


//dfs, 深度搜索, 最深的第一个访问的node就是最左边的结点

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Result struct{
    Depth int
    Val int
}

var ans Result
func helper(node *TreeNode,cur int) Result{
    if node == nil {
        return Result{
            Depth:0,
            Val:0,
        }
    }
    
    if node.Left == nil && node.Right == nil{
        if (cur + 1 > ans.Depth){
            ans.Depth = cur + 1
            ans.Val = node.Val
        }
        
        return Result{
            Depth: cur + 1,
            Val: node.Val,
        }
    }
    
    var t Result
    
    if node.Left  != nil{
        l := helper(node.Left, cur + 1)
        if l.Depth > ans.Depth{
            ans = l
        }
        
        if l.Depth > t.Depth{
            t.Depth = l.Depth
            t.Val = l.Val
        }
    }
    
    if node.Right != nil{
        r := helper(node.Right, cur + 1)        
        if r.Depth > ans.Depth{
            ans = r
        }
        
        if r.Depth > t.Depth{
            t.Depth = r.Depth
            t.Val = r.Val
        }
    }
    return t
}

func findBottomLeftValue(root *TreeNode) int {
    
    //empty tree
    if root == nil {
        return 0
    }
    
    ans.Val = 0
    ans.Depth = 0
    helper(root, 0)
    return ans.Val
}
