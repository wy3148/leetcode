// 207. Course Schedule
// DescriptionHintsSubmissionsDiscussSolution
// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]] 
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
// Note:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.


class Solution {
public:
    
    unordered_map<int, set<int>> preq;
    unordered_map<int, set<int>> canlearn;
    
    set<int> learned;
    
    void dfs(int cur){
        for(auto& p : canlearn[cur]){
            preq[p].erase(cur);
            if (preq[p].size() == 0 && learned.find(p) == learned.end()){
                learned.insert(p);
                dfs(p);
            }
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort, 0 -- numCourses - 1;
        for(auto& v : prerequisites){
            
            //[1,0] [ 1,2 ];
            preq[v[0]].insert(v[1]);  //key:1 (2,0) 
            canlearn[v[1]].insert(v[0]); ///2:1 0:1;
        }
        
        for(int i = 0; i < numCourses; i++){
            if (preq[i].size() == 0){
                learned.insert(i);
                dfs(i);
            }
        }
        return learned.size() == numCourses;
    }
};
