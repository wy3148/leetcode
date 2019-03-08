# 102 Linked list cycle

#### Example

Given -21-&gt;10-&gt;4-&gt;5, tail connects to node index 1, return true

#### Challenge

Follow up:  
Can you solve it without using extra space?

```cpp
    bool hasCycle(ListNode * head) {
        map<ListNode*,bool> visited;
    
        ListNode* cur = head;
        
        while(cur){
            
            if (visited[cur] == true){
                return true;
            }else{
                visited[cur] = true;
            }
            
            cur = cur->next;
        }
        return false;
    }
```

Note: this problem doesn't need slow and fast pointer, we simply use a hashmap to record the visited nodes.

But if we don't want to use extra space, we can use the fast and slow pointer, basic idea is slow point move one step each time, but fast pointer move two steps each time, so eventually, they will be on the same pointer if linked list has a cycle.

```cpp
    bool hasCycle(ListNode * head) {
        // write your code here
        if (head == nullptr || head->next == nullptr) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while (slow && fast){
            if (fast == slow) return true;
            slow = slow->next;
            if (fast->next == nullptr) return false;
            fast = fast->next->next;
        }
        return false;
    }
```



