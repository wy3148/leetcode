

// https://blog.csdn.net/fuxuemingzhu/article/details/84500642

// https://buptwc.com/2018/11/25/Leetcode-947-Most-Stones-Removed-with-Same-Row-or-Column/



//理解题目含义，输入是一系列的row/col 坐标点，坐标点处有石头
//
//



class Solution {
public:
    int count;
    
//那么我们发现了一个规律，对于一个连通的图，我们始终可以删除n-1个石头，其中n是这个连通图内的石头总数
// 我们使用dfs去找到这样的图，每次答案加上这次dfs遍历的石头数减一即可
    
    
    void dfs(vector<vector<int>>& stones,set<pair<int,int>>& curGraph,set<pair<int,int>>& visited, int i, int j){
        for(auto& v : stones){   


            //联通的条件是什么
            // row index or column index is equal to each other, two stones are connected then
            //
            if (visited.find({v[0],v[1]}) == visited.end() && (v[0] == i || v[1] == j)){
                curGraph.insert({v[0],v[1]});
                visited.insert({v[0],v[1]});
                dfs(stones,curGraph,visited,v[0],v[1]);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        count = 0;
        set<pair<int,int>> visited;
        
        //dfs方式查找一个联通的图
        for(auto& v : stones){
            if (visited.find({v[0],v[1]}) == visited.end()){
                set<pair<int,int>> curGraph;
                curGraph.insert({v[0],v[1]});
                visited.insert({v[0],v[1]});
                dfs(stones,curGraph,visited,v[0],v[1]);
                if (curGraph.size() > 1){
                    count += curGraph.size() - 1;
                }
            }
        }
        return count;
    }
};

//[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]] 
// 这样的输入如果图画出来的 他们实际上只有一个联通图
//那么可以移除的stone就是 连通图 结点个数 - 1 


//搜索联通图
//dfs 实现方法, bfs 也可以，或者是
//union find, 并查集

//union find
