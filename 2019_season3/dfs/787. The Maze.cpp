

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


// https://www.lintcode.com/problem/the-maze-ii/description

// https://www.lintcode.com/problem/the-maze-iii/my-submissions



// it's much easier to resolve this problem by bfs

//following DFS is not correct


class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    int op1[4] = {1,-1,0,0};
    int op2[4] = {0,0,-1,1};
    int m, n;
    
    vector<vector<bool>> visited;
    
    bool has;
    
    void dfs(vector<vector<int>> &maze, int i ,int j, int d1, int d2, int pos){
        if (has || i == d1 && j == d2) {
            has = true;
            return;
        }
        int tx = i + op1[pos];
        int ty = j + op2[pos];
        
        if (tx >= 0 && tx < m && ty >=0 && ty < n && visited[tx][ty] == false){
            if (maze[tx][ty] == 0){
                visited[tx][ty] = true;
                dfs(maze,tx,ty,d1,d2,pos);
                 visited[tx][ty] = false;
            }else{
                for(int c = 0;  c < 4; c++){
                    if (pos != c){
                        dfs(maze,i,j,d1,d2,c);
                    }
                }
            }
        }
    }
    
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        if (maze.size() == 0 || maze[0].size() == 0){
            return true;
        }
        m = maze.size(); n = maze[0].size();
        
        visited = vector<vector<bool>>(m, vector<bool>(n,false));
        visited[start[0]][start[1]] = true;
        
        for(int c = 0; c < 4; c++){
            dfs(maze,start[0],start[1],destination[0],destination[1],c);
        }
        return has;
    }
};
