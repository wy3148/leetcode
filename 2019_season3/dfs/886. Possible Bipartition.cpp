// 886. Possible Bipartition
// DescriptionHintsSubmissionsDiscussSolution
// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

// Each person may dislike some other people, and they should not go into the same group. 

// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

// Return true if and only if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// Example 2:

// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:

// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false
 

// Note:

// 1 <= N <= 2000
// 0 <= dislikes.length <= 10000
// 1 <= dislikes[i][j] <= N
// dislikes[i][0] < dislikes[i][1]
// There does not exist i != j for which dislikes[i] == dislikes[j].


//和着色的算法有相似之处


class Solution {
public:
    vector< vector<int> > data;
    vector<int> color;
    
    bool dfs(int i){
        for(int p : data[i]){
            if (color[p] == 0){
                //put in a different group
                color[p] = -color[i];
                if (dfs(p) == false) return false;
            }else if(color[p] == color[i]){
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        //this is very similar to bitcolor    
        if (N <= 1) return true;
        //1- N
        //we use 1 to N; (0 index is not used)
        color = vector<int>(N, 0);
        data = vector<vector<int>>(N);
        for(auto& v : dislikes){
            
            //建立两个有向图
            data[v[0] - 1].push_back(v[1] - 1);
            
            //互相不习惯的图
            data[v[1] - 1].push_back(v[0]  -1);
        }
        
        for(int i = 0; i < N; i++){
            if (color[i] == 0){
                color[i] = 1;
                if (dfs(i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     /**
//      * @param N:  sum of the set
//      * @param dislikes: dislikes peoples
//      * @return:  if it is possible to split everyone into two groups in this way
//      */
//     bool DFS(int cur, vector<int>& visited, vector<vector<int>>& adj){
//         for(int j: adj[cur]){
//             if(visited[j] == 0){
//                 visited[j] = -visited[cur];
//                 if(!DFS(j, visited, adj))
//                     return false;
//             }
//             else if(visited[j] == visited[cur])
//                 return false;
//         }
//         return true;
//     }
//     bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
//         // Write your code here.
//              vector<int> visited(N);
//         vector<vector<int>> adj(N);
//         for(auto& dis: dislikes){
//             adj[dis[0]-1].push_back(dis[1]-1);
//             adj[dis[1]-1].push_back(dis[0]-1);
//         }
        
//         for(int i = 0; i < N; ++ i){
//             if(visited[i] == 0 && (visited[i] = 1) && !DFS(i, visited, adj))
//                 return false;
//         }
//         return true;
//     }
// };





