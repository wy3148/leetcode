// 108. Convert Sorted Array to Binary Search Tree
// DescriptionHintsSubmissionsDiscussSolution
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example:

// Given the sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func bfs(nums []int, start int, end int) *TreeNode {

	if start > end {
		return nil
	}

	if start == end {
		return &TreeNode{Val: nums[start], Left: nil, Right: nil}
	}

	mid := (start + end) / 2
	node := &TreeNode{Val: nums[mid], Left: nil, Right: nil}
	node.Left = bfs(nums, start, mid-1)
	node.Right = bfs(nums, mid+1, end)
	return node
}

func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	return bfs(nums, 0, len(nums)-1)
}