---
description: 'https://www.lintcode.com/problem/merge-k-sorted-lists/description'
---

# 104 merge k sorted linked list

#### Description

Merge _k_ sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given lists:

```text
[
  2->4->null,
  null,
  -1->null
],
```

return `-1->2->4->null`.



solution:

1 use priprity\_queue, push all list nodes and then pop up them to compose a new linked list.

2 merge two linked list firstly, and continue to merge to the end list.

```cpp
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 
class Solution {
public:
    class Compare
    {
        public:
            bool operator() (ListNode* a, ListNode* b){
                return a->val > b->val;
            }
    };
    
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        
        std::priority_queue<ListNode*,vector<ListNode*>,Compare> q;
        for(auto list : lists){
            ListNode* n = list;
            while(n != nullptr){
                q.push(n);
                n = n->next;
            }
        }
        
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        while(!q.empty()){
            ListNode* tmp = q.top(); q.pop();
            if (tmp){
                if (cur){
                    cur->next = tmp;
                }
                cur = tmp;
                cur->next = nullptr;
            }
            if (head == nullptr) head = cur;
        }
        return head;
    }
};
```



```cpp
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:

    ListNode* mergeTwo(ListNode* l1, ListNode* l2){
        if (l1 == nullptr || l2 == nullptr){
            return l1 == nullptr ? l2:l1;
        }
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        
        while (l1 && l2 ){
            ListNode* tmp  = nullptr;
            
           if(l1->val < l2->val){
               tmp = l1;
               l1 = l1->next;
            }else{
                tmp = l2;
                l2 = l2->next;
            }
            
            if (head != nullptr){
                cur->next = tmp;
                cur = tmp;
            }else{
                cur = head = tmp;
            }
        }
        
        while(l1){
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        }

        while(l2){
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }    
        return head;
    }
    
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int i = 0;
        ListNode* prev = nullptr;
        while(i < lists.size()) {
            prev = mergeTwo(lists[i],prev);
            i++;
        }
        return prev;
    }
};
```





