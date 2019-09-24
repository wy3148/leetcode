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



//
// 也可以用dfs递归实现
//
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
