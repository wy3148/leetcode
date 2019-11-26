

// 199. Binary Tree Right Side View
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rightSideView(root *TreeNode) []int {
	var ret []int
	if root == nil {
		return ret
	}

	queue := []*TreeNode{root}

	for len(queue) > 0 {
		size := len(queue)
		var tmp int
		for i := 0; i < size; i++ {
			tmp = queue[i].Val
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
		}
		ret = append(ret, tmp)
		queue = queue[size:]
	}
	return ret
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//dfs的算法， 可以通过一个hashap 记录 depth--nodes的 key/value的mapping
//最后按照深度，保存最后一个结点
var data map[int]int
var maxDepth int

func dfs(root *TreeNode, depth int) {

	if depth > maxDepth {
		maxDepth = depth
	}

	if root == nil {
		return
	}
	data[depth] = root.Val
	if root.Left != nil {
		dfs(root.Left, depth+1)
	}
	if root.Right != nil {
		dfs(root.Right, depth+1)
	}
}

func rightSideView(root *TreeNode) []int {

	//dfs
	data = make(map[int]int)
	dfs(root, 0)

	var ret []int
	for i := 0; i <= maxDepth; i++ {
		ret = append(ret, data[i])
	}
	return ret
}

var data map[int]int
var maxDepth int

func dfs(root *TreeNode, depth int) {

	if depth > maxDepth {
		maxDepth = depth
	}

	if root == nil {
		return
	}
	data[depth] = root.Val
	if root.Left != nil {
		dfs(root.Left, depth+1)
	}
	if root.Right != nil {
		dfs(root.Right, depth+1)
	}
}

func rightSideView(root *TreeNode) []int {

	//dfs

	//mapping的数据结构进一步优化，只需要保存最后一个visited的node val就行了，一定是最右right side view
	data = make(map[int]int)
	dfs(root, 0)

	var ret []int
	for i := 0; i <= maxDepth; i++ {
		ret = append(ret, data[i])
	}
	return ret
}