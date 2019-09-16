// 279. Perfect Squares
// DescriptionHintsSubmissionsDiscussSolution
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.


//子问题的划分；
///需要注意的是 int类型的可能越界

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        
        //子问题 f(i) = f (i - j *j ) 的个数  + 1 ;
        //更新j,更新f(i)的值
        // i = (i - j *j) + j*j 
        //DP的思想
        //
        vector<long int> f (n + 1, 0);
        for(int i = 1; i <= n; i++){
            f[i] = INT_MAX;
            for(int j = 0; j *j <= i; j++){
                f[i] = min(f[i],f[i - j*j] + 1);
            }
        }
        return int(f[n]);
    }
};
