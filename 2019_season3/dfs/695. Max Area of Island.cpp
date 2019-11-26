


class Solution {
public:
    
    int ans;
    
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i, int j, int& cur){
        cur++;
        ans = max(ans,cur);
        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,-1,1};
        for(int c = 0; c < 4; c++){
            int tmpR = i + op1[c];
            int tmpC= j + op2[c];
            
            if (tmpR >=0 && tmpR < grid.size() && tmpC >=0 && tmpC < grid[0].size() && grid[tmpR][tmpC] == 1
               && visited[tmpR][tmpC] == false){
                visited[tmpR][tmpC] = true;
                dfs(grid,visited,tmpR,tmpC,cur);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(); int n = grid[0].size();
        ans = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i =0; i < m; i++){
            
            for(int j = 0;j < n; j++){
                if (grid[i][j] == 1 && visited[i][j] == false){
                    visited[i][j] = true;
                    int size = 0;
                    dfs(grid,visited,i,j,size);
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    
    //面积是，当前 1 + 后续四个方向的面积；
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(); int n = grid[0].size();
        for(int i =0; i< m; i++){
            for(int j =0; j <n; j++){
                if (grid[i][j] == 1){
                    ans = max( ans, dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};