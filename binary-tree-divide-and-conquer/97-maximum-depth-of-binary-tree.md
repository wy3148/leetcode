---
description: 'https://www.lintcode.com/problem/maximum-depth-of-binary-tree/description'
---

# 97 Maximum Depth Of binary tree



#### Description

中文English

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
Example  1:
	Input: tree = {}
	Output: 0
	
	Explanation:
	The height of empty tree is 0.

	
Example  2:
	Input: tree = {1,2,3,#,#,4,5}
	Output: 3
	
	Explanation:
	Like this:
		  1  
		 / \                
		2  3                
		  /  \                
		 4   5 
	
```

#### Related Problems

[650. Find Leaves of Binary Tree](https://www.lintcode.com/problem/find-leaves-of-binary-tree)[155. Minimum Depth of Binary Tree](https://www.lintcode.com/problem/minimum-depth-of-binary-tree)

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
 * @param root: The root of binary tree.
 * @return: An integer
 */
func maxDepth (root *TreeNode) int {
    // write your code here
    if root == nil{
        return 0
    }
    
    d1 := 1 + maxDepth(root.Left)
    d2 := 1 + maxDepth(root.Right)
    
    if (d1 > d2){
        return d1
    }
    return d2
}

```

