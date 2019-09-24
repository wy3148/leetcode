// /
// 743. Network Delay Time
// DescriptionHintsSubmissionsDiscussSolution
// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
 
// Example 1:

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
// Output: 2
 
// Note:

// N will be in the range [1, 100].
// K will be in the range [1, N].
// The length of times will be in the range [1, 6000].
// All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

// [[1,2,1],[2,3,2],[1,3,2]]
// 3
// 1

//联通图，从1开始出发到达的下一个点未必是时间最短的值
// [[1,2,1],[2,3,2],[1,3,4]]
// 3
// 1


//!!!!!!!!!错误的算法
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        //There are N network nodes, labelled 1 to N.
        if (times.size() == 0 || K < 1 || K > N) return 0;
        
        
        //Given times, a list of travel times as directed edges times[i] = (u, v, w)
        //
        
        //1 ~ N
        vector<int> visited(N + 1, 0);
        queue<int> q;
        
        int delay = 0;
        
        //find the start node, source code
        for(auto v : times){
            if (v[0] == K){
                delay = max(delay,v[2]);
                q.push(v[1]);
            }
        }
        
        visited[K] = 1;
        while(!q.empty()){
            
            int size = q.size();
            int tmpDelay = 0;
            
            for(int i  = 0; i < size; i++){

                int pos = q.front(); q.pop();
                visited[pos] = 1;
                
                //find all the nodes which can reached
                for(auto v : times){
                    if (v[0] == pos){
                        if (visited[v[1]] == 0){
                            visited[v[1]] = 1;
                            q.push(v[1]);
                            tmpDelay = max(tmpDelay,v[2]);
                        }
                    }
                }
            }
            delay += tmpDelay;
        }
        
        for(int i =1; i <=N; i++){
            if (visited[i] == 0) return -1;
        }
        return delay;
    }
};



//正确的迪卡斯算法, 最短路径的经典算法
//
//
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        //graph info ,这是转换数据结构，为了更加方便查找 事实上
        unordered_map<int, vector<pair<int,int>> > graph;
        for(auto& v : times){    
            graph[v[0]].push_back({v[1],v[2]});
        }
        
        //only use index from 1 to N,
        //当前源点到目标点的距离的集合信息；每次需要更新
        //默认距离为无穷大，最大值 表示还没到达
        vector<int> dist(N + 1, INT_MAX);

        //源点位置初始化为0
        dist[K] = 0;
        
        //首先找到源点的相邻结点，把最短距离的那个点作为下一个起始点
        //其他结点信息距离还是需要更新
        int d = INT_MAX;
        int next;
        for(auto& v : graph[K]){
            dist[v.first] = v.second;
            if ( d > v.second){
                next = v.first;
                d = dist[v.first];
            }
        }

        queue<int> q;
        q.push(next);

        //已经确定最短距离的结点放入到集合中
        unordered_set<int> visited;
        visited.insert(K);
        visited.insert(next);

        while( !q.empty()){
            int v = q.front(); q.pop();
            for(auto node : graph[v]){
                if (dist[node.first] > dist[v] + node.second ){
                    dist[node.first] = dist[v] + node.second;
                }
            }
        
            //每次需要确定下一个重新作为新的起始点的结点;;
            int tmpD = INT_MAX;
            int shortNode;
            for(int c = 1 ;  c <= N; c++){
                if ( dist[c] < tmpD && visited.find(c) == visited.end()){
                    tmpD = dist[c];
                    shortNode = c;
                }
            }
            if (tmpD < INT_MAX){
                visited.insert(shortNode);
                q.push(shortNode);
            }
        }

        int ret = 0;
        for(int i = 1 ; i <= N; i++){
            if (dist[i] == INT_MAX ) return -1;
            ret = max(ret, dist[i]);
        }
        return ret;
    }
};


//非queue的方式
//因为有N个结点，最多就是做N次的源结点查找
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        //graph info
        unordered_map<int, vector<pair<int,int>> > graph;
        for(auto& v : times){    
            graph[v[0]].push_back({v[1],v[2]});
        }
        
        //only use index from 1 to N
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        vector<int> visited(N + 1, false);
        visited[K] = true;
        
        for(auto& v : graph[K]){
            dist[v.first] = v.second;
        }

        while(true){

            //寻找未被访问最短距离的node
            int tmpD = INT_MAX;
            int tmpNode;
            for(int i = 1; i <= N ; i++){
                if (visited[i] == false && tmpD > dist[i]){
                    tmpD = dist[i];
                    tmpNode = i;
                }
            }
            //找到了，更新相邻结点的结点距离，可能变化或者不变
            if (tmpD < INT_MAX){
                visited[tmpNode] = true;   
                for(auto& v : graph[tmpNode]){
                    if (dist[v.first] > dist[tmpNode] + v.second){
                        dist[v.first] = dist[tmpNode] + v.second;    
                    }
                }
            }else{
                break;
            }
        }
        
        int ret = 0;
        for(int i = 1; i <= N; i++){
            if (dist[i] == INT_MAX) return -1;
            ret = max(ret, dist[i]);
        }
        return ret;
    }
};

