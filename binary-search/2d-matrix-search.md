# 2D matrix search

Description 中文 English Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right. Integers in each column are sorted from up to bottom. No duplicate integers in each row or column. Have you met this question in a real interview?  
Example Example 1:

Input: \[\[3,4\]\] target=3 Output:1 Example 2:

Input: \[ \[1, 3, 5, 7\], \[2, 4, 7, 8\], \[3, 5, 9, 10\] \] target = 3 Output:2 Challenge O\(m+n\) time and O\(1\) extra space

Notes: search from left corner to the right up corner, each position may have one of two directions to move.

```cpp
class Solution {
public:
/**
* @param matrix: A list of lists of integers
* @param target: An integer you want to search in matrix
* @return: An integer indicate the total occurrence of target in the given matrix
*/
int searchMatrix(vector<vector<int>> &matrix, int target) {
// write your code here

    int m = matrix.size();
    if (m == 0) return 0;

    int n = matrix[0].size();
    int i = m-1;
    int j = 0;
    int count = 0;

    while(i >= 0 && j < n){
        if (matrix[i][j] == target) {
            count++;
            j++;
            continue;
        }else if (matrix[i][j] < target){
            j++;
            continue;
        }else{
            i--;
            continue;
        }
    }
    return count;
}
};
```

Description 中文 English Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right. The first integer of each row is greater than the last integer of the previous row. Have you met this question in a real interview?  
Example Example 1: Input: \[\[5\]\],2 Output: false

```text
Explanation: 
false if not included.
```

Example 2: Input: \[ \[1, 3, 5, 7\], \[10, 11, 16, 20\], \[23, 30, 34, 50\] \],3 Output: true

```text
Explanation: 
return true if included.
```

```cpp
class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here

        //take the matrix as a flat std::array;
        //index from 0 ~  n*m - 1
        //position has follow relation, row = mid/n, column = mid % n

        int m = matrix.size();
        if (m == 0) return false;

        int n = matrix[0].size();

        int start = 0;
        int end = m * n - 1;

        while ( start + 1 < end){
            int mid = start + (end - start) / 2;

            int r = mid / n;
            int c = mid % n;

            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        if (matrix[start/n][start%n] == target) return true;
        if (matrix[end/n][end%n] == target) return true;
        return false;
    }
};
```

