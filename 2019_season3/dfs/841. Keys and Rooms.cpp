


//rooms access
//访问过的房间就不需要再访问了


class Solution {
public:
    
    set<int> all;
    
    void dfs(int start, vector<vector<int>>& rooms, vector<bool>& visited){
        all.insert(start);
        visited[start] = true;
        for(auto& v : rooms[start]){
            if (!visited[v]){
                dfs(v,rooms,visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<bool> visited(N,false);
        dfs(0,rooms,visited);
        return all.size() == N; 
    }
};



