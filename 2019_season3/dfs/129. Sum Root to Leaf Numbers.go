// 129. Sum Root to Leaf Numbers
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// Note: A leaf is a node with no children.

// Example:

// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


var sum int

func getSum(cur []int) int{
    
    //no need to reverse
    total := 0
    for i := 0; i < len(cur); i++{
        total = total * 10 + cur[i]
    }
    return total
}

//slice pass in function, need to be careful
//most of time, pointer address is not change, but slice len could change
func dfs(node *TreeNode,cur *[]int){
    if node == nil{
        return
    }
    *cur = append(*cur,node.Val)
    
    if node.Left == nil && node.Right == nil{        
        //must copy, otherwise getSum wil change the content of *cur
        tmp := make([]int, len(*cur))
        copy(tmp,*cur)
        sum += getSum(tmp)
        return
    }
    
    if node.Left != nil{
        dfs(node.Left,cur)
        
        //pop out the last element, backtrack
        (*cur) = (*cur)[:len(*cur) - 1]
    }
    
    if node.Right != nil{
        dfs(node.Right,cur)
        
        //pop out the last element, backtrack
        (*cur) = (*cur)[:len(*cur) - 1]        
    }
}

func sumNumbers(root *TreeNode) int {
    sum = 0
    cur := make([]int,0)
    dfs(root,&cur)
    return sum
}
