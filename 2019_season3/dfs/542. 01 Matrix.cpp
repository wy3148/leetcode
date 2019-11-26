542. 01 Matrix



//
// Exceed the time limit
//
class Solution {
public:
    int m,n;
    int op1[4] = {1,-1,0,0};
    int op2[4] = {0,0,-1,1};
    
    //find the other matrix postion which can be reached from [i,j] while [i,j] value is 0;
    void dfs(int i, int j, vector<vector<int>>& dist,vector<vector<int>>&matrix){
        for(int c =0 ; c < 4; c++){
            int nx = i + op1[c];
            int ny = j + op2[c];
            if (nx >= 0 && nx < m && ny >=0 &&ny < n && matrix[nx][ny] == 1){                
                int d = dist[i][j] + 1;
                if ( dist[nx][ny]  > d ){
                    dist[nx][ny] = d;
                    dfs(nx,ny,dist,matrix);
                }
            }
        }
    }
    
    //distance from o pos to 1 position
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ret;
        m = matrix.size(); n = matrix[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                if (matrix[i][j] == 0){
                    dist[i][j] = 0;
                    dfs(i,j,dist,matrix);
                }
            }
        }
        return dist;
    }
};
