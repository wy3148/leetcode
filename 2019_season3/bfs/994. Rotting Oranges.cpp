
// 994. Rotting Oranges
// DescriptionHintsSubmissionsDiscussSolution
// In a given grid, each cell can have one of three values:

// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {   
        //find the rotten orange firstly
        //start bfs to find all its adjancet positon that has fresh oranges
        //bfs
// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
        
        int fresh = 0;
        int rotten = 0;
        queue<pair<int,int>> q;
        int ret = -1;
        
        int m = grid.size(); 
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    fresh++;
                }else if(grid[i][j] == 2){
                    rotten++;
                    grid[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        //no oranges can change status
        if (fresh == 0) return 0;
        if (rotten == 0) return -1;
        
        int op1[] = {1,-1,0,0};
        int op2[] = {0,0,1,-1};
        
        while(!q.empty()){
            ret++;
            int size = q.size();
            
            //层级遍历，所有的腐烂橘子开始对扩展到相邻结点
            //如果非层级遍历
            for(int c = 0; c < size; c++){
                //once rotten, change to empty
                auto p = q.front(); q.pop();
                for(int c = 0;  c< 4; c++){
                        int tmpC = p.first + op1[c];
                        int tmpR = p.second + op2[c];
                        if (tmpC >=0 && tmpC < m && tmpR >=0 && tmpR < n && grid[tmpC][tmpR] == 1){
                            
                            //受到影响的橘子腐烂之后 修改知道 这样就可以避免多次访问
                            grid[tmpC][tmpR] = 0;
                        
                            q.push({tmpC,tmpR});
                            fresh--;
                        }
                    }
                }
        }
        return fresh == 0 ? ret : -1;
    }
};




//bfs, every level, two pointers to compare each level

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<TreeNode*> tmp;
            for(int c = 0; c < size;c++){
                TreeNode* n  = q.front(); q.pop();
                tmp.push_back(n);
                if (n != nullptr){
                    q.push(n->left);
                    q.push(n->right);
                }
            }
            
            if (tmp.size() == 0){
                continue;
            }
            
            int l = 0; int r = tmp.size() - 1;
            while(l < r){
                
                if (tmp[l]  != nullptr && tmp[r] != nullptr){
                    if (tmp[l]->val != tmp[r]->val) return false;
                }else if (tmp[l] && tmp[r] == nullptr || tmp[l] == nullptr && tmp[r]){
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};