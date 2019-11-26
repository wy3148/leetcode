
//similar to island DFS

//difference the [r0,c0] position may not be colored
//it will be colored when it belongs to the border

class Solution {
public:
    
    int op1[4] = {1,-1,0,0};
    int op2[4] = {0,0,-1,1};
    
    void dfs(vector<vector<int>>& grid, int r, int c, int color, int prevColor){
        
        if (r == 0 || r == grid.size() - 1 || c == 0 || 
           c == grid[0].size() - 1){
            grid[r][c] = color;
        }
        for(int m = 0; m < 4; m++){
            int x = r + op1[m];
            int y = c + op2[m];        
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && 
               grid[x][y] == prevColor){
                dfs(grid,x,y,color,prevColor);
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if (grid.size() == 0  || grid[0].size() == 0) return grid;
        int m = grid.size(); int n = grid[0].size();
        dfs(grid, r0,c0, color, grid[r0][c0]);
        return grid;
    }
};
