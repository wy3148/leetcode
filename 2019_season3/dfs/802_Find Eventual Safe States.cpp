
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    bool dfs(vector<vector<int>>& graph,int start, int curPos){
        if (curPos == start) return false;
        for(auto& next : graph[curPos]){
            bool ret = dfs(graph,start,next);
            if (ret == false) return false;
        }
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //safe, means start from the node, and it will stop at some other node
        //it can't return to the start position
        vector<int> ans;
        int N = graph.size();
        if (N == 0) return ans;

        for(int i = 0; i < N; i++){
            bool ret = true;
            for(auto& v : graph[i]){
                bool r = dfs(graph,i,v);
                if (r == false) ret = r;
            }
            if (ret){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
