# 611 Knight Shortest Path

**Description**  
Given a knight in a chessboard \(a binary matrix with 0 as empty and 1 as barrier\) with a source position, find the shortest path to a destinationposition, return the length of the route.  
Return -1 if knight can not reached.  
  
**Notice**  
source and destination must be empty.  
Knight can not enter the barrier.  
  
  
**Clarification**  
If the knight is at \(x, y\), he can get to the following positions in one step:  
  
\(x + 1, y + 2\)  
\(x + 1, y - 2\)  
\(x - 1, y + 2\)  
\(x - 1, y - 2\)  
\(x + 2, y + 1\)  
\(x + 2, y - 1\)  
\(x - 2, y + 1\)  
\(x - 2, y - 1\)  
  
  
**Example**  
\[\[0,0,0\],  
 \[0,0,0\],  
 \[0,0,0\]\]  
source = \[2, 0\] `destination` = \[2, 2\] return 2  
  
\[\[0,1,0\],  
 \[0,0,0\],  
 \[0,0,0\]\]  
source = \[2, 0\] destination = \[2, 2\] return 6  
  
\[\[0,1,0\],  
 \[0,0,1\],  
 \[0,0,0\]\]  
source = \[2, 0\] destination = \[2, 2\] return -1



\[Problem\]

Given a knight in a chessboard \(a binary matrix with `0` as empty and `1` as barrier\) with a `source` position, find the shortest path to a `destination` position, return the length of the route.   
Return `-1` if knight can not reached.

 **Notice**

source and destination must be empty.  
Knight can not enter the barrier. **Clarification**

If the knight is at \(_x_, _y_\), he can get to the following positions in one step:

```text
(x + 1, y + 2)
(x + 1, y - 2)
(x - 1, y + 2)
(x - 1, y - 2)
(x + 2, y + 1)
(x + 2, y - 1)
(x - 2, y + 1)
(x - 2, y - 1)
```

**Example**

```text
[[0,0,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 2

[[0,1,0],
 [0,0,0],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return 6

[[0,1,0],
 [0,0,1],
 [0,0,0]]
source = [2, 0] destination = [2, 2] return -1
```

\[Idea\]

Examples:

```text


In above diagram Knight takes 3 step to reach from (4, 5) to (1, 1)
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1)  as shown in diagram
```

This problem can be seen as shortest path in unweighted graph. Therefore we use [BFS](http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/) to solve this problem. We try all 8 possible positions where a Knight can reach from its position. If reachable position is not already visited and is inside the board, we push this state into queue with distance 1 more than its parent state. Finally we return distance of target position, when it gets pop out from queue.  
Below code implements BFS for searching through cells, where each cell contains its coordinate and distance from starting node. In worst case, below code visits all cells of board, making worst-case time complexity as O\(N^2\)



```cpp
/**
 * Definition for a point.
 * struct Point {
 *     int x, y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param grid a chessboard included 0 (false) and 1 (true)
     * @param source, destination a point
     * @return the shortest path
     */
    int shortestPath(vector<vector<bool>>& grid, Point& source, Point& destination) {
        // Write your code here
        if(grid.empty() || grid[0].empty()) return -1;
         
        int m = grid.size();
        int n = grid[0].size();
         
        vector<vector<int>> directions = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
         
        vector<vector<int>> record(m, vector<int>(n, INT_MAX)); // record current distance, also plays a role to check if visited
        record[source.x][source.y] = 0;
 
        queue<Point> q;
        q.push(source);
        while (!q.empty()) {
            Point head = q.front();
            q.pop();
            for (int k = 0; k < 8; ++k) {
                int x = head.x + directions[k][0];
                int y = head.y + directions[k][1];
                if (x >=0 && x < m && y >= 0 && y < n && !grid[x][y] &&
                    record[head.x][head.y] + 1 < record[x][y]) {
                    record[x][y] = record[head.x][head.y] + 1;
                    q.push(Point(x, y));
                }
            }
        }
        if (record[destination.x][destination.y] == INT_MAX)
            return -1;
        return record[destination.x][destination.y];
    }
};
```

  




