# 178 Graph valid tree



#### Description

中文English

Given `n` nodes labeled from `0` to `n - 1` and a list of `undirected` edges \(each edge is a pair of nodes\), write a function to check whether these edges make up a valid tree.

You can assume that no duplicate edges will appear in edges. Since all edges are `undirected`, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in edges.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given `n = 5` and `edges = [[0, 1], [0, 2], [0, 3], [1, 4]]`, return true.

Given `n = 5` and `edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]`, return false.

#### Related Problems

[814. Shortest Path in Undirected Graph](https://www.lintcode.com/problem/shortest-path-in-undirected-graph)[750. Portal](https://www.lintcode.com/problem/portal)[589. Connecting Graph](https://www.lintcode.com/problem/connecting-graph)[431. Connected Component in Undirected Graph](https://www.lintcode.com/problem/connected-component-in-undirected-graph)

```cpp
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> v;
        queue<int> q;
        q.push(0);
        v.insert(0);
        for (auto a : edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (v.find(a) != v.end()) return false;
                v.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return v.size() == n;
    }
};
```

