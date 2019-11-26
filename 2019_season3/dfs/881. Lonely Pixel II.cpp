////
// 2 * O( m * n) 时间复杂度
//
class Solution {
public:
    /**
     * @param picture: a 2D char array
     * @param N: an integer
     * @return: return a integer
     */
    int findBlackPixel(vector<vector<char>> &picture, int N) {
        
        //W, B 
        //
        if (picture.size() == 0 || picture[0].size() == 0) return 0;
        int m = picture.size(); int n = picture[0].size();
        
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        
        //rows, each row has number of black 
        for(int i = 0; i < m; i++){
            int b = 0;
            for(int j = 0; j < n;j++){
                if (picture[i][j] == 'B') b++;
            }
            rows[i]= b;
        }
        
        //cols, each col has number of black
         for(int i = 0; i < n; i++){
            int b = 0;
            for(int j = 0; j < m;j++){
                if (picture[j][i] == 'B') b++;
            }
            cols[i]= b;
        }
        int count = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                
                if (picture[i][j] == 'B'){
                    if (rows[i] == N &&  cols[j] == N) count++;
                }
            }
        }
        return count;    
    }
};

//第二次优化，首先遍历一次，统计每行 每列的B 个数

class Solution {
public:
    /**
     * @param picture: a 2D char array
     * @param N: an integer
     * @return: return a integer
     */
    int findBlackPixel(vector<vector<char>> &picture, int N) {
        
        //W, B 
        //
        if (picture.size() == 0 || picture[0].size() == 0) return 0;
        int m = picture.size(); int n = picture[0].size();
        
        vector<int> rows(m,0);
        vector<int> cols(n,0);
        
        //rows, each row has number of black 
        
        // 一次二维数组遍历就可以
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if (picture[i][j] == 'B'){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }


        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                
                if (picture[i][j] == 'B'){
                    if (rows[i] == N &&  cols[j] == N) count++;
                }
            }
        }
        return count;    
    }
};


//利用hashmap的方式 , 在第二次遍历的时候 只需要遍历行数 和hashmap的大小；
//可以减少时间复杂度，如果二维数组是非常巨大的话
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size(), res = 0;
        vector<int> colCnt(n, 0);
        unordered_map<string, int> u;
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++colCnt[j];
                    ++cnt;
                }
            }
            if (cnt == N) ++u[string(picture[i].begin(), picture[i].end())];
        }
        for (auto a : u) {
            if (a.second != N) continue;
            for (int i = 0; i < n; ++i) {
                res += (a.first[i] == 'B' && colCnt[i] == N) ? N : 0;
            }
        }
        return res;


//lonely pixel I 题解，这道题目似乎和dfs的关系不太大
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size(), res = 0;
        vector<int> rowCnt(m, 0), colCnt(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rowCnt[i];
                    ++colCnt[j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    if (rowCnt[i] == 1 && colCnt[j] == 1) {
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};        