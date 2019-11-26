// 547. Friend Circles
// DescriptionHintsSubmissionsDiscussSolution
// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

// Example 1:
// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
// The 2nd student himself is in a friend circle. So return 2.
// Example 2:
// Input: 
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
// so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
// Note:
// N is in range [1,200].
// M[i][i] = 1 for all students.
// If M[i][j] = 1, then M[j][i] = 1.


//dfs 深度搜索
// 主要是二维数组的含义 要搞清楚，本质上是一个 key/value的mapping

// row : 0 , person 0， if M[0][1] = 1; it means the persion 1 is his friend
// if a person has no friend, it ownself is a spearate friend circle.
class Solution {
public:
    
    void dfs(vector<vector<int>>& M, int j){
        M[j][j] = 0;
        for(int p = 0; p < M.size(); p++){
            if (M[j][p] == 1){
                M[j][p] = 0;
                dfs(M,p);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        
        //grid,  each row number reprezent a person, each row is his friends map
        //
        int count = 0;
        
        for(int i = 0; i < n; i++){                
            int cur = 0;
            for(int j = 0; j < n; j++){
                if (i == j && M[i][j] == 1){
                    cur = 1;
                }else if (j != i && M[i][j] == 1){
                    //j is a friend of i
                    M[i][j]= 0;
                    dfs(M,j);
                }
            }
            count += cur;
        }
        return count;
    }
};

//用队列的方式 类似bfs的方法也可以实现该算法，即朋友的朋友放入到遍历队列中；直到当前遍历
//完成那么就是一个friend circle