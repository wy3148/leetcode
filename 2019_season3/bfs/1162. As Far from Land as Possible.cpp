
// 1162. As Far from Land as Possible
// DescriptionHintsSubmissionsDiscussSolution
// Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// If no land or water exists in the grid, return -1.

 

// Example 1:



// Input: [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: 
// The cell (1, 1) is as far as possible from all the land with distance 2.
// Example 2:



// Input: [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: 
// The cell (2, 2) is as far as possible from all the land with distance 4.
 

// Note:

// 1 <= grid.length == grid[0].length <= 100
// grid[i][j] is 0 or 1


//WARNING:
//exceed time limit 
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dist = INT_MIN;
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(); int n = grid[0].size();
        
        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,-1,1};
        
        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                if (grid[i][j] == 0){ 
                    vector<vector<bool>>visited(m, vector<bool>(n,false));
                    visited[i][j] = true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto pos = q.front(); q.pop();
                        if (grid[pos.first][pos.second] == 1){
                            dist = max(dist,abs(pos.first - i) + abs(pos.second - j));
                            break;
                        }
                        for(int c = 0; c < 4; c++){
                            int x = op1[c] + pos.first;
                            int y = op2[c] + pos.second;   
                            if (x >= 0 && x < m && y >=0 && y < n && visited[x][y] == false){   
                                q.push({x,y});
                                visited[x][y] = true;
                            }
                        }
                    }
                }
            }
        }
        return dist == 0 || dist == INT_MIN ? - 1 : dist;
    }
};
