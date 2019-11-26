
// Back
// 178. Graph Valid Tree
// Description
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


//DFS and BFs can be used to resolve the issues
class Solution {
public:
    unordered_map<int, set<int>> graph;

    bool dfs(int i, vector<bool>& visited){
        
        for(auto& v : graph[i]){
            
            if(visited[v]) return false;
            //remove each other edge
            graph[i].erase(v);
            graph[v].erase(i);
            visited[v] = true;
            if (dfs(v,visited) == false) return false;
        }
        return true;
    }
    
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        
        if (n <= 1) {
            return true;
        }
        // write your code here
        for(auto& v: edges){
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }
        
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if (visited[i] == false && graph[i].size() >  0 ){
                visited[i] = true;
                if( dfs(i,visited) == false) return false;
            }
        }
        for(int i = 0; i < n; i++){
            if (visited[i] == false) return false;
        }
        return true;
    }
};