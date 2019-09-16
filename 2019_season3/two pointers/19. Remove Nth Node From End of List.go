
// 19. Remove Nth Node From End of List
// DescriptionHintsSubmissionsDiscussSolution
// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

// Follow up:

// Could you do this in one pass?


//链表的快慢指针，two pointers,方法，注意边界条件
//几个特殊的n的取值 和 list 链表的元素个数

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if n <= 0 {
        return head
    }
    
    fast := head
    slow := head
    ret := 1
	count := 0

    for fast != nil && ret <= n{
        fast = fast.Next;
        ret++
        count++
    }
    
	prev := slow
	
	//这种情况的遍历，slow的位置就是需要移除掉的那个元素
	//所以我们用一个prev元素来记录之前的位置
    for fast != nil{
        count++
        fast = fast.Next
        prev = slow
        slow = slow.Next
	}
	
    prev.Next = slow.Next
    if (count <= n){
        return head.Next
    }
    return head
}
