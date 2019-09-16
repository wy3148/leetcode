// 103. Binary Tree Zigzag Level Order Traversal
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func reverse(data []int) []int {
	if len(data) == 0 {
		return data
	}
	l := 0
	r := len(data) - 1
	for l < r {
		data[l], data[r] = data[r], data[l]
		l++
		r--
	}
	return data
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	var ret [][]int
	if root == nil {
		return ret
	}

	var q []*TreeNode
	q = append(q, root)

	zig := true

	for len(q) > 0 {
		size := len(q)

		var tmp []int
		for i := 0; i < size; i++ {
			tmp = append(tmp, q[i].Val)
			if q[i].Left != nil {
				q = append(q, q[i].Left)
			}
			if q[i].Right != nil {
				q = append(q, q[i].Right)
			}
		}

		if zig {
			ret = append(ret, tmp)
		} else {
			tmp = reverse(tmp)
			ret = append(ret, tmp)
		}
		zig = !zig

		q = q[size:]
	}
	return ret
}
