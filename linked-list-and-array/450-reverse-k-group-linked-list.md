# 450 reverse K group linked list



#### Description

中文English

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.  
Only constant memory is allowed.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given this linked list: `1->2->3->4->5`

For k = 2, you should return: `2->1->4->3->5`

For k = 3, you should return: `3->2->1->4->5`

#### Related Problems

[767. Reverse Array](https://www.lintcode.com/problem/reverse-array)[451. Swap Nodes in Pairs](https://www.lintcode.com/problem/swap-nodes-in-pairs)[170. Rotate List](https://www.lintcode.com/problem/rotate-list)[36. Reverse Linked List II](https://www.lintcode.com/problem/reverse-linked-list-ii)[35. Reverse Linked List](https://www.lintcode.com/problem/reverse-linked-list)

Notes:

1.  we should have a basic function that, reverse a linked list\(recursive or non-recursive function\)
2.  then we divide linked list into K group, if less than k, we don't reverse, we just return.
3.  step2 should be recursive.

```cpp
/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:

    ListNode* reverse(ListNode* head){
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* r = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return r;
    }
    
    /**
     * @param head: a ListNode
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode * reverseKGroup(ListNode * head, int k) {
        // write your code her
        ListNode* root = head;
        int count = 0;
        while (root){
            count++;
            root = root->next;
        }
        
        if (count < k) {
            return head;
        }

        ListNode* cur = head;
        for(int i = 0; i < k -1 ; i++){
            cur = cur->next;
        }

        ListNode* nextHead = cur->next;
        cur->next = nullptr;
        ListNode* r = reverse(head);
        head->next = reverseKGroup(nextHead,k);
        return r;
    }
};
```

basic reverse of linked list, none-recursive function,

```cpp
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

/**
 * @param head: n
 * @return: The new head of reversed linked list.
 */
func reverse (head *ListNode) *ListNode {
// write your code here
    if head == nil || head.Next == nil {
        return head
    }
    
    var prev *ListNode
    var next *ListNode
    
    cur := head
    //n1,n2,n3 
    //cur
    
    for cur != nil{
        next = cur.Next
        cur.Next = prev
        prev = cur 
        cur = next
    }
    return prev 
}

```

