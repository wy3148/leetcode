// Description
// 中文
// English
// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

// Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

// 1.There is only one ball and one destination in the maze.
// 2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// 3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// 5.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input:
// map = 
// [
//  [0,0,1,0,0],
//  [0,0,0,0,0],
//  [0,0,0,1,0],
//  [1,1,0,1,1],
//  [0,0,0,0,0]
// ]
// start = [0,4]
// end = [3,2]
// Output:
// false
// Example 2:

// Input:
// map = 
// [[0,0,1,0,0],
//  [0,0,0,0,0],
//  [0,0,0,1,0],
//  [1,1,0,1,1],
//  [0,0,0,0,0]
// ]
// start = [0,4]
// end = [4,4]
// Output:
// true


//The tricky part of this problem, when we reach the wall, at position
// [x,y]

// next time the start position is from the wall, it should start from [x-1,y]
//or [x, y - 1]


class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        if (maze.size() ==0 || maze[0].size() == 0) return false;
        
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> q; 
        q.push({start[0],start[1]});
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        visited[start[0]][start[1]] = true;

        while(!q.empty()){
            auto pos = q.front(); q.pop();
            if(pos.first == destination[0] && pos.second== destination[1]) return true;
            
            //four directions
            //down
            int x = pos.first + 1;
            int y = pos.second;
            
            while (x >= 0 && x < m && maze[x][y] == 0){
                x++;
            }
            
            if (visited[x-1][y] == false){
                q.push({x-1,y});
                visited[x-1][y] = true;
            }
            
            //up
            x = pos.first - 1;
             while (x >= 0 && x < m && maze[x][y] == 0){
                x--;
            }           
            if (visited[x+1][y] == false){
                q.push({x+1,y});
                visited[x+1][y] = true;
            }
            
            //left
            y = pos.second - 1;
            x = pos.first;
            while (y >= 0 && y < n && maze[x][y] == 0){
                y--;
            }           
             if (visited[x][y+1] == false){
                q.push({x,y+1});
                visited[x][y+1] = true;
            }              
            
            //right
            y = pos.second + 1;
            while (y >= 0 && y < n && maze[x][y] == 0){
                y++;
            }           
            if (visited[x][y-1] == false){
                q.push({x,y-1});
                visited[x][y-1] = true;
            }                 
        }
        return false;
    }
};



//the simpler way to implement 4 directions



class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        //bfs
        int m = maze.size(); 
        if (m == 0) return false;
        int n = maze[0].size();
        if (n == 0) return false;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        
        int op1[] ={1,-1,0,0};
        int op2[] = {0,0, -1,1};
    
        while(!q.empty()){
            auto p = q.front(); q.pop();
            
            if (p.first == destination[0] && p.second == destination[1]) return true;
            
            
            //we try four different directions
            for(int i = 0; i < 4; i++){
                int x = p.first;
                int y = p.second;
                
                //for each direction, we go straight until we 
                //reach the wall 
                while(x >= 0 && x <m && y >=0 && y< n && maze[x][y] == 0){
                    x += op1[i];
                    y += op2[i];
                }  
                
                //when we reach the wall, we need to take a step back
                //then change directions next time
                x -= op1[i];
                y -= op2[i];
                
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return false;
    }
};

// https://www.lintcode.com/problem/the-maze-ii/


//依然是bfs算法，只是queue的 element 不仅包含了位置信息，而且还包含了 steps信息；
//在朝着同一个方向滚动的时候，每while循环一次 都要递增临时的steps；
//最后的位置如果符合条件就是 previous steps + 当前临时滚动的steps
class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        //bfs
        int m = maze.size(); 
        if (m == 0) return false;
        int n = maze[0].size();
        if (n == 0) return false;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue< vector<int> > q;
        q.push({start[0],start[1],0});
        
        int op1[] ={1,-1,0,0};
        int op2[] = {0,0, -1,1};
        
        int steps = INT_MAX;
    
        while(!q.empty()){
            auto p = q.front(); q.pop();
            
            if (p[0] == destination[0] && p[1] == destination[1]){
                steps = min(steps,p[2]);
                continue;
            };
            
            //we try four different directions
            for(int i = 0; i < 4; i++){
                int x = p[0];
                int y = p[1];
                int tmp = 0;
                
                //for each direction, we go straight until we 
                //reach the wall 
                while(x >= 0 && x <m && y >=0 && y< n && maze[x][y] == 0){
                    x += op1[i];
                    y += op2[i];
                    tmp++;
                }  
                
                //when we reach the wall, we need to take a step back
                //then change directions next time
                x -= op1[i];
                y -= op2[i];
                
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y,p[2] + tmp -1 });
                }
            }
        }
        return steps == INT_MAX ? -1 : steps;
    }
};


