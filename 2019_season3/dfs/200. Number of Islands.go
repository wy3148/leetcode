// 200. Number of Islands
// DescriptionHintsSubmissionsDiscussSolution
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3




//DFS golang version


var op1 [4]int = [4]int{1,-1,0,0}
var op2 [4]int = [4]int{0,0,-1,1}

func dfs(grid [][]byte, x, y int){
    for  c:=0; c<4; c++{
        nx := x + op1[c]
        ny := y + op2[c]
        
        if nx >=0 && nx < len(grid) && ny >=0 && ny < len(grid[0]) &&
        grid[nx][ny] == '1'{
            grid[nx][ny] = '0'
            dfs(grid,nx,ny)
        }
    }
}

func numIslands(grid [][]byte) int {
    ret := 0 
    if len(grid) == 0 || len(grid[0]) == 0 {
        return ret
    }
    
    for i := 0; i < len(grid); i++{
        
        for j := 0;j < len(grid[0]); j++{
            if grid[i][j] == '1'{
                ret++
                grid[i][j] = '0'
                dfs(grid,i,j)
            }
        }
    }
    
    return ret
}
