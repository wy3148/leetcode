---
description: 'https://www.lintcode.com/problem/topological-sorting/description'
---

# 127 topological-sorting

#### Description

中文English

Given an directed graph, a topological order of the graph nodes is defined as follow:

* For each directed edge `A -> B` in graph, A must before B in the order list.
* The first node in the order can be any node in the graph with no nodes direct to it.

Find any topological order for the given graph.

You can assume that there is at least one topological order in the graph.Have you met this question in a real interview?  YesProblem Correction

#### Clarification

[Learn more about representation of graphs](http://www.lintcode.com/help/graph)

#### Example

For graph as follow:

![picture](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcThE9AgZZszyhwe0o9qpp3VyizdIj9kWwMY50HiQEysXvkSLsoZ)

The topological order can be:

```text
[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...
```

#### Challenge

Can you do it in both BFS and DFS?



firstly

1, like deep clone of graph nodes, we need to know how to iterator the 

graph nodes with 'queue'

2. for graph, we nee to store  the edges of each node

3. for graph, after iterator, we put those nodes without precondition/Prerequisite.

4, during the bfs process, we decrease the edge degree for each related node, once the node has no precondition anymore, we put it

into queue.

```cpp
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        
        vector<DirectedGraphNode*> res;
        if (graph.size() == 0){
            return res;
        }
        
        unordered_map<DirectedGraphNode*, unordered_set<DirectedGraphNode*>> nodeMap;
        unordered_set<DirectedGraphNode*> nodeSet;
        std::queue<DirectedGraphNode*> q;
        
        for (auto v : graph){
            if (nodeSet.find(v) == nodeSet.end()){
                nodeSet.insert(v);
                q.push(v);
            }
            
            while (!q.empty()){
                DirectedGraphNode* n = q.front(); q.pop();
                for ( auto neighbor : n->neighbors){
                    nodeMap[neighbor].insert(n);
                    if(nodeSet.find(neighbor) == nodeSet.end()){
                        nodeSet.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        
        queue<DirectedGraphNode*> orderQ;
        
        for (auto n : nodeSet){
            if (nodeMap.find(n) == nodeMap.end()){
                res.push_back(n);
                orderQ.push(n);
            }
        }
        
        while (!orderQ.empty()){
            DirectedGraphNode* n = orderQ.front(); orderQ.pop();
            for(auto neighbor : n->neighbors){
                nodeMap[neighbor].erase(n);
                if (nodeMap[neighbor].size() == 0){
                    res.push_back(neighbor);
                    orderQ.push(neighbor);
                }
            }           
        }
        return res;
    }
};
```

