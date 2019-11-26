


//BFS 算法相对比较好理解一些，没有递归函数

class Solution {
public:

    int op1[4] = {1,-1,0,0};
    int op2[4] = {0,0,-1,1};
    string dir[4] = {"1","-1","2","-2"};
    
    /**
     * 
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        
        unordered_set<string> islands;
        
        if (grid.size() == 0  || grid[0].size() == 0) return 0;
        
        int m = grid.size(); int n = grid[0].size();
        
        for(int i = 0;i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if (grid[i][j] == 1){
                    grid[i][j] = 0;
                    std::queue<pair<int,int>> q;
                    q.push({i,j});
                    string shape("s;");
                    while(!q.empty()){
                        auto p = q.front(); q.pop();
                        for(int c = 0; c < 4; c++){
                            int tx = op1[c] + p.first;
                            int ty = op2[c] + p.second;
                            if (tx >=0 && tx < m && ty >=0 && ty < n &&
                            grid[tx][ty] == 1){
                                
                                //get the position starting from (i,j)
                                //
                                shape += to_string(tx - i) + to_string(ty-j);
                                grid[tx][ty]= 0;
                                q.push({tx,ty});
                            }
                        }
                    }
                    islands.insert(shape);
                }
            }
        }
        return islands.size();
    }
};

///
/// DFS的实现方法，递归函数的定义和实现
class Solution {
public:

    int m,n;
    set<string> islands;
    int op1[4] = {1,-1,0,0};
    int op2[4] = {0,0,-1,1};
    
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
     
     void dfs(vector<vector<int>> &grid, int startX, int startY, int i, int j, string& cur){
         if (i >= 0 && i < m && j >=0 && j < n && grid[i][j] == 1){
             grid[i][j] = 0;
             cur += to_string(i - startX) + to_string(j - startY);
             
             //更简洁的写法           
             for(int move  = 0; move < 4; move++){
                dfs(grid,startX,startY, i + op1[move] , j + op2[move], cur);
             }
             
            //  dfs(grid,startX,startY, i + 1 , j, cur);
            //  dfs(grid,startX,startY, i - 1 , j, cur);
            //  dfs(grid,startX,startY, i, j + 1, cur);
            //  dfs(grid,startX,startY, i, j - 1, cur);
         }
     }
     
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        // write your code here
        if (grid.size() ==0 || grid[0].size() ==0 ) return 0;
        m = grid.size(); n =grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    string cur;
                    dfs(grid,i,j,i,j,cur);
                    islands.insert(cur);
                }
            }
        }
        return islands.size();
    }
};