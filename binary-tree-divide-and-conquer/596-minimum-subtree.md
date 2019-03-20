# 596 minimum subtree

Description

中文English

Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

LintCode will print the subtree which root is your return node.  
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input:
     1
   /   \
 -5     2
 / \   /  \
0   2 -4  -5 

Output:1
```

Example 2:

```text
Input:
   1
Output:1
```

Every time, we need to update the result, so we create a 'Result' struct,

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/**
 * @param root: the root of binary tree
 * @return: the root of the minimum subtree
 */

import("math")

type Result struct{
    sum int
    node *TreeNode
}

var ret Result

func helper(root* TreeNode) int {
    if root == nil {
        return 0
    }
    
    l := helper(root.Left)
    r := helper(root.Right)
    tmp := root.Val + l + r 
    if ret.node == nil || tmp < ret.sum{
        ret.node = root
        ret.sum = tmp
    }
    return tmp
}

func findSubtree (root *TreeNode) *TreeNode {
    // write your code here
    ret.sum = math.MaxInt32
    ret.node = nil
    helper(root)
    return ret.node
}

```

