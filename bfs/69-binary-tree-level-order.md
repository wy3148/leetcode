# 69 Binary Tree Level Order

#### Description

中文English

Given a binary tree, return the level order traversal of its nodes' values. \(ie, from left to right, level by level\).Have you met this question in a real interview?  YesProblem Correction

#### Example

Given binary tree `{3,9,20,#,#,15,7}`,

```text
    3
   / \
  9  20
    /  \
   15   7
```

return its level order traversal as:

```text
[
  [3],
  [9,20],
  [15,7]
]
```

#### Challenge

Challenge 1: Using only 1 queue to implement it.

Challenge 2: Use BFS algorithm to do it.

Go version:

```cpp
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/**
 * @param root: A Tree
 * @return: Level order a list of lists of integer
 */
func levelOrder (root *TreeNode) [][]int {
    // write your code here
    res := make([][]int,0)
    queue := make([]*TreeNode,0)
    if root == nil{
        return res
        
    }
    queue = append(queue,root)
    for len(queue) > 0{
        size := len(queue)
        var tmp []int
        
        for i := 0 ; i < size; i++{
            node := queue[i]
            tmp = append(tmp,node.Val)
            
            if node.Left != nil{
                queue = append(queue,node.Left)
            }
            if node.Right != nil{
                queue = append(queue,node.Right)  
            }
        }
        
        queue = queue[size:]
        res = append(res,tmp)
    }
    return res
}

```

