// Description
// 中文
// English
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
// Output: true.
// Example 2:

// Input: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
// Output: false.
// Related Problems


class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
    
        //0 ~ n -1 
        vector<bool> visited(n,false);
        unordered_map<int, set<int>> nodes;
        std::queue<int>q;
        q.push(0);
        set<int> record;
        record.insert(0);
        
        for (auto v : edges){
            //无向, edges建立对应关系
            nodes[v[0]].insert(v[1]);
            nodes[v[1]].insert(v[0]);
        }
        
        while(!q.empty()){
            int n = q.front(); q.pop();
            for(auto v : nodes[n]){
                
                //访问0,1; 可以移除 1:0对应关系
                nodes[v].erase(n);
                
                //node has been visited before
                if (record.find(v) != record.end()){
                    return false;
                }
                record.insert(v);
                q.push(v);
            }
        }
        return record.size() == n; 
    }
};
