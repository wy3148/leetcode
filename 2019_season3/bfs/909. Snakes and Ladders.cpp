// 909. Snakes and Ladders
// DescriptionHintsSubmissionsDiscussSolution
// On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the board, and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:


// You start on square 1 of the board (which is always in the last row and first column).  Each move, starting from square x, consists of the following:

// You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
// (This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations, regardless of the size of the board.)
// If S has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to S.
// A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.  The destination of that snake or ladder is board[r][c].

// Note that you only take a snake or ladder at most once per move: if the destination to a snake or ladder is the start of another snake or ladder, you do not continue moving.  (For example, if the board is `[[4,-1],[-1,3]]`, and on the first move your destination square is `2`, then you finish your first move at `3`, because you do not continue moving to `4`.)

// Return the least number of moves required to reach square N*N.  If it is not possible, return -1.


//BFS:
//下一次跳跃的起始位置可能有6个位置，所以需要把六个的位置加入到下一次search的候选中；
//层级遍历
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0 || n == 1) return 0;
        
        // S from 1 to 6,  就是丢撒子游戏，遇到ladder就可以直接爬上去
        //关键点是计算int到位置的对应关系
        //board[r][c]
        //r,c 的关系
        
        map<int, pair<int,int>> posData;
        //方式计算错误；要从底层向上
        // int start = n * n;        
        // //不需要什么计算公式，直接把数组遍历一遍就可以,每一行需要换一个移动方向；
        // bool left = true;
        // for(int i = 0; i < n; i++){
        //     if (left){
        //         for(int j = 0; j < n; j++){
        //             posData[start] = {i,j};
        //             start--;
        //         }
        //         left = false;
        //     }else{
        //         for(int j = n-1; j >=0; j--){
        //             posData[start] = {i,j};
        //             start--;                 
        //         }
        //         left = true;
        //     }
        // }
        
        int start = 1;
        bool left = true;
        
        for(int i = n - 1; i >=0; i--){
            if (left){
                for(int j = 0; j < n; j++) {
                    posData[start] = {i,j};
                    start++;
                }
                left = false;
            }else{
                for(int j = n - 1; j >=0; j--){
                    posData[start] = {i,j};
                    start++;                  
                }
                left = true;
            }
        }
        
        queue<int> q;
        q.push(1);
        int move = 0;
        vector<bool> visited(n * n + 1 , false);
        visited[1] = true;
        
        while(!q.empty()){
            int size = q.size();
            for(int s = 0; s  < size; s++){
                int v = q.front(); q.pop();     
                if (v == n *n ) return move;
                
                for(int i = 1; i <= 6; i++){    
                    int tmp = v + i;
                    if (tmp > n * n) break;
                    
                    pair<int,int> nextPos = posData[tmp]; 
                    int r = nextPos.first;
                    int c = nextPos.second;
                    
                    if (board[r][c] != -1){
                        tmp = board[r][c];
                    }
                    
                    if (visited[tmp] == false){
                        q.push(tmp);
                        visited[tmp] = true;
                    }
                }
            }
            move++;
        }
        return -1;
    }
};