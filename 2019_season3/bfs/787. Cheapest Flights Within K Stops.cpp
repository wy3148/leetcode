// 787. Cheapest Flights Within K Stops
// DescriptionHintsSubmissionsDiscussSolution
// There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:


// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:


// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
// Note:

// The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// The size of flights will be in range [0, n * (n - 1) / 2].
// The format of each flight will be (src, dst, price).
// The price of each flight will be in the range [1, 10000].
// k is in the range of [0, n - 1].
// There will not be any duplicated flights or self cycles.


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        //BFS
        //起始节点就是src的出发的航班，bfs搜索的节点包含当前的花费和stops的数值
        //超过K就不需要继续往下搜索；符合K并且找到dst就需要更新当前的cost，和最终cost做比较
        
        //初始的时候可以进行数据转换 src --(dst,cost)的hashmap 方便搜索
        
        unordered_map<int,vector<pair<int,int>>> flights_data;  
        for(auto v : flights){
            flights_data[v[0]].push_back({v[1],v[2]});            
        }
        
        int ret = INT_MAX;
        
        //element in queue,   <src, cost, stops>
        queue<vector<int>> q;
        q.push({src,0,0});
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if (cur[0] == dst){
                ret = min(ret, cur[1]);
            }
            
            //next stops
            for(auto n : flights_data[cur[0]]){
                    
                if (cur[2] > K ){
                    continue;
                }
                
                q.push({n.first, cur[1] + n.second, cur[2] + 1});
            }
        }
        
        return ret == INT_MAX ? -1 : ret;
    }
};


//修正过的算法!!!

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        //BFS
        //起始节点就是src的出发的航班，bfs搜索的节点包含当前的花费和stops的数值
        //超过K就不需要继续往下搜索；符合K并且找到dst就需要更新当前的cost，和最终cost做比较
        
        //初始的时候可以进行数据转换 src --(dst,cost)的hashmap 方便搜索
        
        unordered_map<int,vector<pair<int,int>>> flights_data;  
        for(auto v : flights){
            flights_data[v[0]].push_back({v[1],v[2]});            
        }
        
        int ret = INT_MAX;
        
        //element in queue,   <src, cost, stops>
        queue<vector<int>> q;
        q.push({src,0,0});
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if (cur[0] == dst){
                ret = min(ret, cur[1]);
            }
            if (cur[2] > K ){
                continue;
            }
            
            
            //next stops
            for(auto& n : flights_data[cur[0]]){
                
                
                //!!!重要的一步，如果当前的结果已经比现有的记录cost花费更多
                //我们就没有必要继续走这条线路了
                if (cur[1] + n.second > ret) continue;
                
                
                q.push({n.first, cur[1] + n.second, cur[2] + 1});
            }
        }
        
        return ret == INT_MAX ? -1 : ret;
    }
};