


class Solution {
public:
    
    bool isBound(vector<vector<int>>& A, int i , int j){
        if (i == 0 || i == A.size() - 1 || j == 0 || j == A[0].size() -1 ) return true;
        return false;
    }
    
    void dfs(vector<vector<int>>& A, int i, int j, int& cur, bool& reach){
        if (i >= 0 && i < A.size() && j >= 0 && j < A[0].size() && A[i][j] == 1){
            cur++;
        }else{
            return;
        }
        
        bool bound = isBound(A,i ,j);
        if (bound){
            reach = true;
            return;
        }
        
        //如何遍历一个二维数组，dfs的方式，递归调用；
        A[i][j] = 0;
        dfs(A,i + 1, j, cur, reach);
        dfs(A,i - 1, j, cur, reach);
        dfs(A,i, j + 1, cur, reach);
        dfs(A,i, j - 1, cur, reach);
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        
        int total = 0;
        for(int i = 0; i < A.size(); i++){
            
            for(int j = 0; j < A[0].size(); j++){
                
                if (A[i][j] == 1){
                    int cur = 0;
                    bool reach = false;
                    dfs(A,i, j, cur, reach);
                    
                    if (!reach){
                        total += cur;   
                    }
                }
            }
        }
        return total;
    }
};
