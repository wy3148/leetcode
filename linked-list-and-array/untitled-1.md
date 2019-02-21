---
description: 'https://www.lintcode.com/problem/merge-two-sorted-lists/description'
---

# 165. Merge Two Sorted Lists



#### Description

Merge two sorted \(ascending\) linked lists and return it as a new sorted list. The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
Example 1:
	Input: list1 = null, list2 = 0->3->3->null
	Output: 0->3->3->null


Example 2:
	Input:  list1 =  1->3->8->11->15->null, list2 = 2->null
	Output: 1->2->3->8->11->15->null
	
	
```

```cpp
       if (l1 == nullptr || l2 == nullptr){
            return l1 == nullptr ? l2 : l1;
        }
        
        ListNode dummpyHead;
        ListNode* cur = &dummpyHead;
        
        while (l1 && l2){
            if (l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        while (l1){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        
        while (l2){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        return dummpyHead.next;
```

{% code-tabs %}
{% code-tabs-item title="Golang" %}
```text
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

/**
 * @param l1: ListNode l1 is the head of the linked list
 * @param l2: ListNode l2 is the head of the linked list
 * @return: ListNode head of linked list
 */
func mergeTwoLists (l1 *ListNode, l2 *ListNode) *ListNode {
    // write your code here
    
    dummyHead := &ListNode{
        Val:0,
        Next: nil,
    }
    
	cur := dummyHead

	for l1 != nil && l2 != nil {
		if l1.Val <= l2.Val {
			cur.Next = l1
			l1 = l1.Next
		} else {
			cur.Next = l2
			l2 = l2.Next
		}
		cur = cur.Next
	}

	for l1 != nil {
		cur.Next = l1
		l1 = l1.Next
		cur = cur.Next
	}

	for l2 != nil {
		cur.Next = l2
		l2 = l2.Next
		cur = cur.Next
	}
    return dummyHead.Next
}

```
{% endcode-tabs-item %}
{% endcode-tabs %}

