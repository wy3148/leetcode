# 433 Number of Islands I, II

#### Description

Given a boolean 2D matrix, `0` is represented as the sea, `1` is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Find the number of islands.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given graph:

```text
[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]
```

return `3`.

bfs

```cpp
class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
     
    typedef struct Pos{
        public:
        int first;
        int second;
        Pos(int x, int y){
            first = x;
            second = y;
        }
    }Pos;
    
    void bfs(vector<vector<bool>> &grid, int x , int y){
        
        int m = grid.size();
        int n =  grid[0].size();
        
        std::queue<Pos> q;
        q.push(Pos(x,y));
        grid[x][y] = false;
        
        while (!q.empty()){
            
            Pos tmp = q.front(); q.pop();
            
            int r = tmp.first;
            int c = tmp.second;
            
            if (r + 1 < m && grid[r+1][c]){
                q.push(Pos(r+1,c));
                grid[r+1][c] = false;
            }

            if (r - 1 >= 0 && grid[r-1][c]){
                q.push(Pos(r-1,c));
                grid[r-1][c] = false;
            }
            if (c + 1 < n && grid[r][c + 1]){
                q.push(Pos(r,c + 1));
                grid[r][c + 1] = false;
            }
            if (c - 1 >= 0 && grid[r][c -1]){
                q.push(Pos(r,c - 1));
                grid[r][c -1] = false;
            }
        }
    }
     
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        
        int m = grid.size();
        if (m == 0) return 0;
        int n =  grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++){
            for (int j = 0;j < n; j++){
                
                if (grid[i][j]){
                    res++;
                    bfs(grid,i,j);
                }
            }
        }
        return res;
    }
};
```

dfs

```cpp
class Solution {
public:


    void dfs(vector<vector<bool>> &grid, int m, int n,
    int i, int j){
    
        if (i + 1 < m && grid[i+1][j]){
            grid[i+1][j] = false;
            dfs(grid,m,n,i+1,j);
        }

        if (i -1 >= 0 && grid[i-1][j]){
            grid[i-1][j] = false;
            dfs(grid,m,n,i-1,j);
        }
        
        if (j + 1 < n && grid[i][j + 1]){
            grid[i][j + 1] = false;
            dfs(grid,m,n,i,j + 1);
        }
        
        if (j - 1 >= 0 && grid[i][j - 1]){
            grid[i][j - 1] = false;
            dfs(grid,m,n,i,j - 1);
        }
    }

    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int res = 0;
        
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    res++;
                    grid[i][j] = false;
                    dfs(grid,m,n,i,j);
                }
            }
        }
        return res;
    }
};
```



#### Example

**Example 1:**

```text
Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
Output: [1,1,2,2]
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
```

**Example 2:**

```text
Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
Output: [1,1,2,2]
```

#### Related Problems

[860. Number of Distinct Islands](https://www.lintcode.com/problem/number-of-distinct-islands)[804. Number of Distinct Islands II](https://www.lintcode.com/problem/number-of-distinct-islands-ii)[677. Number of Big Islands](https://www.lintcode.com/problem/number-of-big-islands)[629. Minimum Spanning Tree](https://www.lintcode.com/problem/minimum-spanning-tree)[589. Connecting Graph](https://www.lintcode.com/problem/connecting-graph)[477. Surrounded Regions](https://www.lintcode.com/problem/surrounded-regions)[433. Number of Islands](https://www.lintcode.com/problem/number-of-islands)[432. Find the Weak Connected Component in the Directed Graph](https://www.lintcode.com/problem/find-the-weak-connected-component-in-the-directed-graph)



