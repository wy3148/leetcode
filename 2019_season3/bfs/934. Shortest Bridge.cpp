// 934. Shortest Bridge
// DescriptionHintsSubmissionsDiscussSolution
// In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

// Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

// Example 1:

// Input: [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
 

// Note:

// 1 <= A.length = A[0].length <= 100
// A[i][j] == 0 or A[i][j] == 1




// basic idea is we have two islands, so firstly use bfs to search islands,
// and store the position information pair<int, int > into separate island;
// And the minimum distance is the (row difference and column difference)

//we need to calculate the each position distance and store the shortest one
class Solution {
public:
    int shortestBridge(vector<vector<int>>& A)    {
    
        if (A.size() == 0 || A[0].size() == 0) return 0;
        
        int m = A.size(); int n = A[0].size();
        vector< vector<pair<int,int>> > bridge;
        
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        
        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,1,-1};
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                if (A[i][j] == 1 && visited[i][j] == false){
                    visited[i][j] = true;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<pair<int,int>> tmp;
                    while(!q.empty()){
                        auto p = q.front(); q.pop();
                        tmp.push_back({p.first,p.second});
                        for( int move = 0; move < 4; move++){
                            int x = op1[move] + p.first;
                            int y = op2[move] + p.second;
                            if (x >=0 && x < m && y >=0 && y < n && visited[x][y] == false && 
                               A[x][y] == 1){
                                q.push({x,y});
                                visited[x][y] = true;
                            }
                        }  
                    }
                    bridge.push_back(tmp);
                } 
            }
        }
            
        int distance = INT_MAX;    
        for(auto& b1 : bridge[0]){
            for(auto&b2  : bridge[1]){   
                distance = min(distance, abs(b1.first - b2.first) + abs(b1.second - b2.second) - 1);
            }
        }
        return distance;
    }
};
