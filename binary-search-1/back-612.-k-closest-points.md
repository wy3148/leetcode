# Back 612. K Closest Points



#### Description

中文English

Given some `points` and an `origin` point in two-dimensional space, find `k` points which are nearest to the `origin`.  
Return these points sorted by distance, if they are same in distance, sorted by the x-axis, and if they are same in the x-axis, sorted by y-axis.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input: points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3 
Output: [[1,1],[2,5],[4,4]]
```

Example 2:

```text
Input: points = [[0,0],[0,9]], origin = [3, 1], k = 1
Output: [[0,0]]
```

#### Related Problems

[460. Find K Closest Elements](https://www.lintcode.com/problem/find-k-closest-elements)

```cpp
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

Point target;

class Solution {
public:
    class Compare {
        public:
        bool operator()(Point& a, Point& b){
            int d1 = (a.x - target.x) * (a.x - target.x) +
            (a.y - target.y) * (a.y - target.y);
            int d2  =(b.x - target.x) * (b.x - target.x) +
            (b.y - target.y) * (b.y - target.y);
            
            if (d1 == d2){
                if (a.x == b.x){
                    return a.y < b.y;
                }else{
                    return a.x < b.x;
                }
            }
            return d1 < d2;
        }
    };
    
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        
        target = origin;
        priority_queue<Point, vector<Point>, Compare> q;
        vector<Point> res;
        
        for( Point p : points){
            if (q.size() <= k){
                q.push(p);
            }else{
                Point tmp =q.top(); q.pop();
                q.push(p);
            }
        }
        while(q.size() > k){
            q.pop();
        }
        
        while(!q.empty()){
            Point p = q.top(); q.pop();
            res.push_back(p);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```

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

