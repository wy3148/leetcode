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

func numIslands(grid [][]byte) int {
    
    m := len(grid)
    if m == 0 {
        return 0
    }
    
    n := len(grid[0])
    if n == 0 {
        return 0
    }
        
    //queue
    var q [][]int
    
    op1 := []int{1,-1,0,0}
    op2 := []int{0,0,-1,1}
    count := 0
    
    for i:= 0 ; i < m; i++ {
        
        for j := 0; j < n; j++{
            
            if grid[i][j] == '1'{
                count++
                q = append(q,[]int{i,j});
                grid[i][j] = 0
                
                for len(q) > 0{
                    pos := q[0]              
                    for c:= 0; c < 4; c++{                
                        tmpX := pos[0] + op1[c]
                        tmpY := pos[1] + op2[c]
                        if (tmpX >=0 && tmpX < m &&
                            tmpY >=0 && tmpY < n && grid[tmpX][tmpY] == '1'){
                            grid[tmpX][tmpY] = 0
                            q = append(q,[]int{tmpX,tmpY})
                        }
                    }
                    //pop out the first element, start from '1'
                    q = q[1:]
                }
            } 
        }        
    }
    return count
}