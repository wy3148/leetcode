---
description: 'https://www.lintcode.com/problem/rehashing/description'
---

# 129 rehashing

#### Description

The size of the hash table is not determinate at the very beginning. If the total size of keys is too large \(e.g. size &gt;= capacity / 10\), we should double the size of the hash table and rehash every keys. Say you have a hash table looks like below:

`size=3`, `capacity=4`

```text
[null, 21, 14, null]
       ↓    ↓
       9   null
       ↓
      null
```

The hash function is:

```text
int hashcode(int key, int capacity) {
    return key % capacity;
}
```

here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same hashcode 1 \(21 % 4 = 9 % 4 = 1\). We store them in the hash table by linked list.

rehashing this hash table, double the capacity, you will get:

`size=3`, `capacity=8`

```text
index:   0    1    2    3     4    5    6   7
hash : [null, 9, null, null, null, 21, 14, null]
```

Given the original hash table, return the new hash table after rehashing .

For negative integer in hash table, the position can be calculated as follow:

* **C++/Java**: if you directly calculate -4 % 3 you will get -1. You can use function: a % b = \(a % b + b\) % b to make it is a non negative integer.
* **Python**: you can directly use -1 % 3, you will get 2 automatically.

Have you met this question in a real interview?  



This topic is about the basic design theory of hashmap, when the size of elements 

in a hashmap achieves a fixed size, how can we rehashing?



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
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int newSize = hashTable.size() * 2;
        vector<ListNode*> newHashTable(newSize,nullptr);
        
        for(auto node : hashTable){
            if (node){
                ListNode* head = node;
                while(head){
                    int code = head->val;
                    int key;
                    if (code >= 0){
                        key = code % newSize;
                    }else{
                        key = (code % newSize + newSize) % newSize;
                    }
                    
                    ListNode* start = newHashTable[key];
                    if (start == nullptr){
                        newHashTable[key] = new ListNode(code);
                    }else{
                        ListNode* newNode = new ListNode(code);
                        while(start->next != nullptr){
                            start = start->next;
                        }
                        start->next = newNode;
                    }
                    head = head->next;
                }
            }
        }
        return newHashTable;
    }
};

```





