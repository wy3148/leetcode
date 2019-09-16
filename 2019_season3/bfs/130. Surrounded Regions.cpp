// 130. Surrounded Regions
// DescriptionHintsSubmissionsDiscussSolution
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.




//一种是从非边界的0位置开始搜索，搜到一个类似island的孤岛； 
//然后修改为所有岛的位置的值

//类似搜索到island的bfs算法

//还有一种反向思路是从边缘的0开始，把所有connected的点给标识一下，都为0； 其他都修改为x

#include "general.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //'X' and 'O'
        
        int m = board.size();
        if (m == 0) return ;
        int n = board[0].size();
        if (n == 0) return;
        
        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,-1,1};
        
        for(int i = 0; i < m ; i++){
            for(int j = 0;j < n; j++){
                if (board[i][j] == 'O'){
                    if (i == 0 || i == m -1 || j == 0 || j == n -1){
                        continue;
                    }else{
                        vector<vector<bool>> visited(m, vector<bool>(n,false));
                        vector<pair<int,int>> nodes;
                        queue<pair<int,int>> q;
                        q.push({i,j});
                        visited[i][j] = true;
                        bool valid = true;
                        while(!q.empty()){
                            auto p = q.front(); q.pop();
                            nodes.push_back({p.first,p.second});
                            
                            if (p.first == 0 || p.first == m - 1 || p.second == 0 ||
                               p.second == n - 1){
                                valid = false;
                                break;
                            }
                            
                            for(int c = 0; c < 4; c++){
                                
                                int x = op1[c] + p.first;
                                int y = op2[c] + p.second;
                                
                                if (x >=0 && x < m && y >= 0 && y < n && board[x][y] == 'O' &&
                                   visited[x][y] == false){
                                    q.push({x,y});
                                    visited[x][y] = true;
                                }
                            }
                        }
                        
                        if (valid){
                            for(auto& v : nodes){
                                board[v.first][v.second] = 'X';
                            }
                        }
                    }
                }
            }
        }
    }
};