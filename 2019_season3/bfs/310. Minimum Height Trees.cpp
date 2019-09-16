// 310. Minimum Height Trees
// DescriptionHintsSubmissionsDiscussSolution
// For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Example 1 :

// Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

//         0
//         |
//         1
//        / \
//       2   3 

// Output: [1]
// Example 2 :

// Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5 

// Output: [3, 4]
// Note:

// According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


//原始的算法时间复杂度过高，需要对每一个结点做bfs遍历；

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> ret;
        if (edges.size() == 0){
            ret.push_back(n -1);
            return ret;
        }
        //constrcut the root , leaves map
        //leaves to root map
        unordered_map<int, vector<int>> nodeMap;
        for(auto& v : edges){
            nodeMap[v[0]].push_back(v[1]);
            nodeMap[v[1]].push_back(v[0]);
        }
        
        unordered_map<int,vector<int>> distMap;
        int minDst = n;
        
        // n个结点
        //0 ~ n -1 ;
        //dept = n - 1
        
        for(int i = 0; i < n; i++){
            queue<int> q;
            set<int> nodeset;
            q.push(i);
            vector<bool> visited(n,false);
            int depth = 0;
            visited[i] = true;
            while(!q.empty()){
                int size = q.size();
                for(int c = 0; c < size; c++){
                    int cur = q.front(); q.pop();
                    nodeset.insert(cur);
                    for(auto& p: nodeMap[cur]){
                        if (visited[p] == false){
                            q.push(p);
                            visited[p] = true;
                        }
                    }
                }
                depth++;

                if (depth > minDst) break;
            }
            if (nodeset.size() == n){
                distMap[depth].push_back(i);
                minDst = min(minDst,depth);
            }
        }
        return distMap[minDst];
    }
};

//考核的拓扑排序

