

// 拓扑排序
// 每一个结点的叶子结点当个为1的时候， 可以放入queue;
// 最低高度一定是，某一个root结点的叶子结点比较多；


// 这道题虽然是树的题目，但是跟其最接近的题目是Course Schedule 课程清单和Course Schedule II 课程清单之二。由于LeetCode中的树的题目主要都是针对于二叉树的，而这道题虽说是树但其实本质是想考察图的知识，这道题刚开始在拿到的时候，我最先想到的解法是遍历的点，以每个点都当做根节点，算出高度，然后找出最小的，但是一时半会又写不出程序来，于是上网看看大家的解法，发现大家推崇的方法是一个类似剥洋葱的方法，就是一层一层的褪去叶节点，最后剩下的一个或两个节点就是我们要求的最小高度树的根节点，这种思路非常的巧妙，而且实现起来也不难，跟之前那到课程清单的题一样，我们需要建立一个图g，是一个二维数组，其中g[i]是一个一维数组，保存了i节点可以到达的所有节点。我们开始将所有只有一个连接边的节点(叶节点)都存入到一个队列queue中，然后我们遍历每一个叶节点，通过图来找到和其相连的节点，并且在其相连节点的集合中将该叶节点删去，如果删完后此节点也也变成一个叶节点了，加入队列中，再下一轮删除。那么我们删到什么时候呢，当节点数小于等于2时候停止，此时剩下的一个或两个节点就是我们要求的最小高度树的根节点啦

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
        // 1: (2,0,3)
        unordered_map<int, unordered_set<int>> nodeMap;
        for(auto& v : edges){
            nodeMap[v[0]].insert(v[1]);
            nodeMap[v[1]].insert(v[0]);
        }
        
        queue<int> q;
        unordered_set<int> visited;
        for(auto& v : nodeMap){
            if (v.second.size() == 1){
                q.push(v.first);
                visited.insert(v.first);
            }
        }
        
        while(!q.empty()){
            ret.clear();
            int size = q.size();
            for(int i= 0;i < size; i++){
                auto cur = q.front(); q.pop();
                ret.push_back(cur);
                for(auto node : nodeMap[cur]){
                    if (visited.find(node) != visited.end()){
                        continue;
                    }
                    nodeMap[node].erase(cur);
                    if (nodeMap[node].size() == 1){
                        visited.insert(node);
                        q.push(node);
                    }
                }
            }
        }
        return ret;
    }
};
