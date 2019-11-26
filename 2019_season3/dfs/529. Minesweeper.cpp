// 529. Minesweeper
// DescriptionHintsSubmissionsDiscussSolution
// Let's play the minesweeper game (Wikipedia, online game)!

// You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

// Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

// If a mine ('M') is revealed, then the game is over - change it to 'X'.
// If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
// If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
// Return the board when no more squares will be revealed.
 

// Example 1:

// Input: 

// [['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'M', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E']]

// Click : [3,0]

// Output: 

// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]

// Explanation:

// Example 2:

// Input: 

// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]

// Click : [1,2]

// Output: 

// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'X', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]




class Solution {
public:
    
    //move 8 directions
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    
    vector<vector<int>> record;
    int m,n ;
    
    void dfs(vector<vector<char>>& board, int x, int y){ 
        board[x][y] = 'B';
        for (int k = 0; k < 8; k++) {
            int tx = x + dx[k];
            int ty = y + dy[k];
            if (0 <= tx && tx < m && 0 <= ty && ty < n && 'B' != board[tx][ty]) {
                if (record[tx][ty]) {
                    board[tx][ty] = char(record[tx][ty] + '0');
                } else if ('E' == board[tx][ty]) {
                    board[tx][ty] = 'B';
                    dfs(board, tx, ty);
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        //dfs 也可以实现
        m = board.size(); n = board[0].size();
        
        record = vector<vector<int>>(m, vector<int>(n,0));
        
        //game over
        if (board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        //统计所有的位置的mine信息 周边mine的个数
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (board[i][j] == 'M'){
                    
                    //current pos is Mine
                    record[i][j] = -1;
                    
                    for(int c = 0; c < 8; c++){
                        int x = i + dx[c];
                        int y = j + dy[c];
                        if ( x >= 0 && x < m && y >= 0 && y < n){
                            if ( board[x][y] != 'M'){
                                record[x][y]++;
                            }
                        }
                    }
                }            
            }
        }
        
        int x = click[0]; int y = click[1];
        
        if ('E' == board[x][y]) {  // blank square
            if (record[x][y]) {   // There are mines around, you can modify the numbers.
                board[x][y] = char(record[x][y] + '0');
                return board;
            } else {    // There are no mines around, deep search
                //周边没有mines，当前位置是empty,那么就可以改为B，但需要继续进行深度搜索
                dfs(board, x, y);
            }
        }
        return board;
    }
};



///BFS解法
//当前click的位置
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int m = board.size();
        if (m == 0) return board;
        int n = board[0].size();
        if (n == 0) return board;
        
        
        queue< pair<int,int> > q;
        q.push({click[0], click[1]});
        
        int op1[] = {1,-1,1,-1,0,0,1,-1};
        int op2[] = {0,0,1,-1,-1,1,-1,1};
        
        while(!q.empty()){
            
            auto pos = q.front(); q.pop();
            int count = 0;
            
            if (board[pos.first][pos.second] == 'M'){
                board[pos.first][pos.second] = 'X';
            }else{
                vector<vector<int>> neighbors;
                for(int i  =0; i < 8; i++){    
                    int x = op1[i] + pos.first;
                    int y = op2[i] + pos.second;
                    
                    //统计相邻八个方向的雷的个数;;;
                    if (x >=0 && x < m && y >=0 && y < n){
                        if (board[x][y] == 'M'){
                            count++;
                        }else if (count == 0 && board[x][y] == 'E'){
                            neighbors.push_back({x,y});
                        }
                    }
                }
                
                if (count > 0 ){
                    //当雷的个数不为0，个数；
                     board[pos.first][pos.second] = count + '0';
                }else{
                    
                    board[pos.first][pos.second]= 'B';
                    //相邻结点没有雷，肯定可以改他们的值为B；然后继续从B的相邻结点搜索
                    for(auto& v : neighbors){
                        board[v[0]][v[1]] = 'B';    
                        q.push({v[0],v[1]});
                    }
                }
            }
        }
        return board;
    }
};
