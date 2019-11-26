

114. Flatten Binary Tree to Linked List
DescriptionHintsSubmissionsDiscussSolution
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

          

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(root *TreeNode)  {
    if root == nil || (root.Left == nil && root.Right == nil){
        return
    }
    
    prev := root
    var stack []*TreeNode
    stack = append(stack,root)
    
    for len(stack) > 0 {    
        //pop up the head element
        node := stack[len(stack) - 1]

        //golang style stack
        stack = stack[:len(stack) - 1]
        
        if node.Right != nil{
            stack = append(stack,node.Right)
        }
        
        if node.Left != nil{
            stack = append(stack,node.Left)    
        }
        
        if node != root{
            prev.Right = node
            prev.Left = nil
            prev = node
        }
    }
    root.Left = nil
}
