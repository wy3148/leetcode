// https://www.lintcode.com/problem/walls-and-gates/description


// 663. Walls and Gates
// Description
// 中文
// English
// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a ROOM, that room should remain filled with INF

// Have you met this question in a real interview?  
// Example
// Example1

// Input:
// [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output:
// [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

// Explanation:
// the 2D grid is:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// the answer is:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4
// Example2

// Input:
// [[0,-1],[2147483647,2147483647]]
// Output:
// [[0,-1],[1,2]]


class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        
        //计算从gate到room的距离， 从gate对相邻结点的搜索
        //类似level order traverse，那么第一时间搜索到的room
        //一定是最近的距离
        
        //-1 - A wall or an obstacle.
        // 0 - A gate.
        int m  = rooms.size(); 
        if (m == 0) return;
        int n = rooms[0].size();
        if (n == 0) return;
        queue<pair<int,int>> q; 
        
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        
        int op1[] = {0,0,-1,1};
        int op2[] = {-1,1,0,0};
        int distance = 0;
        while(!q.empty()){
            distance++;
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto p = q.front(); q.pop();
                for(int c = 0; c < 4; c++){
                    int x = p.first + op1[c];
                    int y = p.second + op2[c];
                    
                    //reaches a room, 如果一个room已经被访问过了
                    //值不是2147483647, 那一定是最近的gate访问到的
                    if (x >=0 && x <m && y >=0 && y < n && rooms[x][y] == 2147483647){
                        rooms[x][y] = distance;
                        q.push({x,y});
                    }
                }  
            }
        }
    }
};