# 618 search graph node

\[Problem\]

Given a `undirected graph`, a `node` and a `target`, return the nearest node to given node which value of it is target, return `NULL` if you can't find.

There is a `mapping` store the nodes' values in the given parameters.

 **Notice**

It's guaranteed there is only one available solution

\[Idea\]

BFS

The solution provided here is quite typical as it use a queue to travese the graph node level by level if the given node could be set as the root node. Initially the queue is constructed with the only element, the root node. By next level, it means the neighbor list the current node holds.

Considering the possibility of loops, a hash map is introduced here to avoid duplicate visiting. Once a node is visited, it will be pushed into the hashmap.

The difference between the graph and tree is 

```cpp
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph a list of Undirected graph node
     * @param values a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node an Undirected graph node
     * @param target an integer
     * @return the a node
     */
    UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        // Write your code here
        queue<UndirectedGraphNode*> q;
        set<UndirectedGraphNode*> hash;
         
        q.push(node);
        hash.insert(node);
        while(!q.empty()) {
            UndirectedGraphNode* head = q.front();
            q.pop();
            if(values[head] == target) {
                return head;
            }
            for(UndirectedGraphNode* n : head->neighbors) {
                if(hash.find(n) == hash.end()) {
                    hash.insert(n);
                    q.push(n);
                }
            }
        }
        return NULL;
    }
};
```

