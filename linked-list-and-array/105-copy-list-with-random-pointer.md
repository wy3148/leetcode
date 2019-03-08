# 105  Copy List with Random Pointer

#### Description

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.Have you met this question in a real interview?  YesProblem Correction

#### Challenge

Could you solve it with O\(1\) space?

Notes:

1 use a hashmap to store the old node ==&gt; new node relation.

2 use a set to check if new node is created or not

3 when constructing the relationship of node, we need to construct the 'next' pointer and also 'random' pointer.

```cpp
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        
        //old node to new ndoe map
        map<RandomListNode*, RandomListNode*> nodeMap;
        
        //all existing nodes in a set
        set<RandomListNode*> nodeSet;
        
        RandomListNode* root = head;
        while(root){
            if (nodeSet.find(root) == nodeSet.end()){
                nodeSet.insert(root);
                nodeMap[root] = new RandomListNode(root->label);
            }
            if (root->random){
                if (nodeSet.find(root->random) == nodeSet.end()){
                    nodeSet.insert(root->random);
                    nodeMap[root->random] = new RandomListNode(root->random->label);
                }
            }
            root = root->next;
        }
        
        root = head;
        while(root){
            if (root->next){
                nodeMap[root]->next = nodeMap[root->next];         
            }
            if (root->random){
                nodeMap[root]->random = nodeMap[root->random];
            }
            root = root->next;
        }
        
        return nodeMap[head];
    }
};
```

