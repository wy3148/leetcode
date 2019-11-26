

// //binary tree  root -- leaf maximum sum value

// 337. House Robber III

// 337. House Robber III
// DescriptionHintsSubmissionsDiscussSolution
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \
//      3   1

// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \
//  1   3   1

// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//this has the divide && conquer algothrigm
// two different ways

// 1 add root value , and not add its direct child nodes
// 2 not add root value, add its left, right child nodes
func dfs(node *TreeNode, cur int) int {
	if node == nil {
		return cur
	}

	//add current node value, not add its direct left and right child
	d1 := cur + node.Val
	if node.Left != nil {
		d1 += dfs(node.Left.Left, 0)
		d1 += dfs(node.Left.Right, 0)
	}
	if node.Right != nil {
		d1 += dfs(node.Right.Left, 0)
		d1 += dfs(node.Right.Right, 0)
	}

	d2 := cur
	d2 += dfs(node.Left, 0)
	d2 += dfs(node.Right, 0)
	if d1 > d2 {
		return d1
	}
	return d2
}

func rob(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return dfs(root, 0)
}
 