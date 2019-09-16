// Given a linked list, rotate the list to the right by k places, where k is non-negative.

// Example 1:

// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
// Example 2:

// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL


import "fmt"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    
    if head == nil{
        return head
    }
    
    n := head
    count := 0
    
    tail := head
    for n != nil{
        count++;
        tail = n
        n = n.Next
    }
    
    
    //原始k=2,list nodes 为5， 从tail应该移动 5-2 =3 steps
    //获取新的head位置
    k = count - k%count;
    
    if count == 1 || k <= 0{
        return head
    }
    //巧妙一点思路是tail和head首尾相连起来，然后从tail处进行移动k次就行，在k次位置就是新的head；
    //k 之前的那个位置就是新的tail
    tail.Next = head
    start := tail
    for k > 0{
        start = start.Next
        k--
    }
    h := start.Next
    start.Next = nil
    return h
}
