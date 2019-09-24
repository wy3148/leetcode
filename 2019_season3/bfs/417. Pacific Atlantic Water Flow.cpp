// 417. Pacific Atlantic Water Flow
// DescriptionHintsSubmissionsDiscussSolution
// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

// Note:

// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.



// Given the following 5x5 matrix:

//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic

// Return:

// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).


//解题思路？

// !!!!!
//错误！！！！！！！Warning
///算法的时间复杂度过高了
//对每一个结点都做bfs搜索
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        //对某一个位置，做bfs，直到能达到edges或者两边都走到，走不下去
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        int m = matrix.size(); int n = matrix[0].size();
        
        vector<vector<int>> ret;
        
        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,-1,1};
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                vector<vector<bool>> visited(m,vector<bool>(n,false));
                visited[i][j] = true;
                queue<pair<int,int>> q;
                q.push({i,j});
                
                bool pacific = false;
                bool alt = false;
                
                while(!q.empty()){
                    auto p = q.front(); q.pop();
                    if (p.first == 0 || p.second == 0) pacific = true;
                    if (p.first == m - 1 || p.second == n - 1) alt = true;
    
                    
                    if (pacific && alt){
                        ret.push_back({i,j});
                        break;
                    }
                    
                    for(int c = 0; c <4; c++){    
                        int x = op1[c] + p.first;
                        int y = op2[c] + p.second;
                        
                        //the height of next cell is equal or lower to its previous cell
                        //
                        if (x >=0 && x < m && y >= 0 && y < n && visited[x][y] == false && 
                           matrix[x][y] <= matrix[p.first][p.second]){
                            visited[x][y] = true;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
        return ret;
    }
};


class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        //对某一个位置，做bfs，直到能达到edges或者两边都走到，走不下去
        vector<vector<int>> ret;
        if (matrix.size() == 0  || matrix[0].size() == 0) return ret;
        int m = matrix.size(); int n = matrix[0].size();
        vector<vector<pair<bool,bool>> data(m,vector<pair<bool,boool>>(n,{false,false}));

        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,-1,1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bool search = false;
                if (i == 0 || i == m -1){
                    search = true;
                    data[i][j].first = true;
                }
                if (j == 0 || j == n -1){
                    search = true;
                    data[i][j].second = true;
                }

                if (search){
                    vector<vector<bool>> visited(m,vector<bool>(n,false));
                    visited[i][j] = true;
                    queue<pair<int,int>> q; 
                    q.push({i,j});

                    while(!q.empty()){
                        auto pos = q.front(); q.pop();
                        for(int c = 0; c < 4; c++){
                            int x = op1[c] + pos.first;
                            int y = op2[c] + pos.second;
                            if (x >=0 && x < m && y >=0 && y < n && visited[x][y] == false &&
                            matrix[x][y] <= matrix[pos.first][pos.second]){
                                q.push({x,y});
                                visited[x][y] = true;
                                if (data[pos.first][pos.second].first){
                                    data[x][y].first = data[pos.first][pos.second].first; 
                                }
                                if (data[pos.first][pos.second].second){
                                    data[x][y].second = data[pos.first][pos.second].second; 
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (data[i][j].first  && data[i][j].second){
                    ret.push_back({i,j});
                }
            }
        }
        return ret;
    }
};
