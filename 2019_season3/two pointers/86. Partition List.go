
// 86. Partition List
// DescriptionHintsSubmissionsDiscussSolution
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5



//算法:
//we maintain two lists, each list has two pointers, pinter for left side, and other point 
// is for right side
// finally we need to link them together

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    
    //等于有两段list,每个list有two pointers
    
    //two pointers
    //stack
    var left *ListNode
    var right *ListNode
    
    var newHead *ListNode
    var newRight *ListNode
    
    
    //head = 1->4->3->2->5->2, x = 3
    //1->2->2->4->3->5
    
    node := head
    
    for node != nil {
        if node.Val < x{
            if newHead == nil{
                newHead = node
            }
            if left != nil{
                left.Next = node
                left = node
            }else{
                left = node
            }
            node = node.Next
        }else{
            if newRight == nil{
                newRight = node
            }
            if right != nil{
                right.Next = node
                right = node
            }else{
                right = node
            }
            node = node.Next 
        }
    }
    
    if right != nil {
        right.Next = nil
    }
    
    if newHead == nil{
        newHead = newRight
    }
    
    if left != nil{
        left.Next = newRight
    }
    return newHead
}
