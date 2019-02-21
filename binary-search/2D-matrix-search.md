---
description: >-
https://www.lintcode.com/problem/search-a-2d-matrix-ii/description
---

# 38 2D matrix search

Description
中文
English
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.
Have you met this question in a real interview?  
Example
Example 1:

Input:
[[3,4]]
target=3
Output:1
Example 2:

Input:
[
[1, 3, 5, 7],
[2, 4, 7, 8],
[3, 5, 9, 10]
]
target = 3
Output:2
Challenge
O(m+n) time and O(1) extra space


Notes:
search from left corner to the right up corner,
each position may have one of two directions to move.

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
};```

