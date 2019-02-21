# zombie in matrix

Given a 2D grid, each cell is either a wall `2`, a zombie `1` or people `0` \(the number zero, one, two\).Zombies can turn the nearest people\(up/down/left/right\) into zombies every day, but can not through wall. How long will it take to turn all people into zombies? Return `-1` if can not turn all people into zombies.Have you met this question in a real interview? Yes**Example**

Given a matrix:

```text
0 1 2 0 0
1 0 0 2 1
0 1 0 0 0
```

return `2`

`bfs: this requires the level traverse of binary tree.`

```cpp

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;



//1, zombile, 0, people, 2 wall
int zombile(std::vector<std::vector<int>>& res){
	int count = 0;

	int m = res.size();
	int n = res[0].size();

	queue<pair<int,int>> q;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (res[i][j] == 1){
				q.push(pair<int,int>{i,j});
			}
		}
	}

	std::vector<std::vector<bool>> visited(m,std::vector<bool>(n,false));

	while (!q.empty()){
		int size = q.size();
		for (int i = 0; i < size; i++){
			auto pos = q.front(); q.pop();
			int x = pos.first;
			int y = pos.second;

			//up down left,right
			if (x + 1 < m && visited[x+1][y] == false 
				&& res[x+1][y] != 2){
				q.push(pair<int,int>{x+1,y});
				visited[x+1][y] = true;
				res[x+1][y] = 1;
			}
			if (x - 1 >= 0 && visited[x-1][y] == false
				&& res[x-1][y] != 2){
				q.push(pair<int,int>{x-1,y});
				visited[x-1][y] = true;
				res[x-1][y] = 1;
			}
			if (y + 1< n && visited[x][y + 1] == false
				&& res[x][y + 1] != 2){
				q.push(pair<int,int>{x,y + 1});
				res[x][y + 1] = true;
				res[x][y + 1] = 1;
			}
			if (y - 1 >= 0 && visited[x][y - 1] == false
				&& res[x][y - 1] != 2){
				q.push(pair<int,int>{x,y - 1});
				visited[x][y-1] = true;
				res[x][y - 1] = 1;
			}
		}
		count++;
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if (res[i][j] == 0) return 0;
		}
	}

	return count - 1;
}

int main(int argc, char** argv){

	vector<std::vector<int>> res = {
		{0,0,1},
		{1,0,2},
		{0,0,0}
	};
	cout << zombile(res) << "\n";
	return 0;
}

```

```cpp
  int zombie(vector<vector<int>>& grid) {
        // Write your code here
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
 
        queue<Position> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push(Position(i, j));
                }
            }
        }
                     
        int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int days = 0;
        while (!q.empty()) {
            days++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Position head = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = head.x + d[k][0];
                    int y = head.y + d[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        q.push(Position(x, y));
                    }
                }
            }
        }
 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    return -1;
                }
            }
        }
 
        return days - 1; // -1 is needed here beccause in the last day of the loop, it must turn 0 people into zombie otherwise it wouldn't end here. This day doesn't count
    }
```

