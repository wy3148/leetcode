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