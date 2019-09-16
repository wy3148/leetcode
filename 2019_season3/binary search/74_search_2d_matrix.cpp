// 74. Search a 2D Matrix
// DescriptionHintsSubmissionsDiscussSolution
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

func searchMatrix(matrix [][]int, target int) bool {
    
    m := len(matrix)
    
    if m == 0 {
        return false
    }
    
    n := len(matrix[0])
    if n == 0 {
        return false
    }
    
    l := 0
    r := m *n - 1
    
    // mid := ( 0 + 11) / 2 = 5
    for l + 1 < r {
        mid := (l + r) / 2
        
        //get position,, divide the number of columns
        x := mid / n
        y := mid % n
        
        if (matrix[x][y] == target){
            return true
        }else if (matrix[x][y] > target){
            r = mid
        }else{
            l = mid
        }
    }
    
    if (matrix[l/n][l%n] == target || matrix[r/n][r%n] == target){
        return true
    }
    return false
}
