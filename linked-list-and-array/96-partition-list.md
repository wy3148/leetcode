# 96 partition list



#### Description

中文English

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
Example 1:
	Input:  list = null, x = 0
	Output: null
	
	Explanation:
	The empty list Satisfy the conditions by itself.

Example 2:
	Input:  list = 1->4->3->2->5->2->null, x = 3
	Output: 1->2->2->4->3->5->null
	
	Explanation:  
	keep the original relative order of the nodes in each of the two partitions.
```

```cpp
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

/**
 * @param head: The first node of linked list
 * @param x: An integer
 * @return: A ListNode
 */
 
//  import("fmt")
 
func partition (head *ListNode, x int) *ListNode {
    // write your code here
    
    var dummySmall ListNode
    var dummyBig ListNode
    
    cur := head 
    small := &dummySmall
    big := &dummyBig
    
    
    for cur != nil{
        if cur.Val < x {
            small.Next = cur
            small = cur
        }else{
            big.Next = cur
            big = cur
        }
        cur = cur.Next
    }
    
    small.Next = dummyBig.Next
    big.Next = nil
    return dummySmall.Next
}

```

Notes: when we are not sure about the exact head node of the list, we can think about using dummy list node.



