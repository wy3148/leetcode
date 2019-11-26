



515. Find Largest Value in Each Tree Row

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//bfs
import "math"
func largestValues(root *TreeNode) []int {
    
    var ret []int 
    
    if root == nil{
        return ret
    }
    var queue []*TreeNode
    
    queue = append(queue,root)
    
    for len(queue) > 0 {
        v := math.MinInt32
        size := len(queue)
        
        for i:=0; i < size; i++{
            if v < queue[i].Val {
                v = queue[i].Val
            }
            
            if queue[i].Left != nil{
                queue = append(queue,queue[i].Left)
            }
            
            if queue[i].Right != nil{
                queue = append(queue,queue[i].Right)
            }
        }
        ret = append(ret,v)
        queue = queue[size:]
    }
    return ret
}






//用一个hashmap 保存 dfs 记录每个深度的结点值，保留最大的值就可以

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
    
    //depth : max value  map
    map<int,int> data;
    
    vector<int> ret;
    void dfs(TreeNode* root, int depth){
        if (!root) return;
         if (data.find(depth) == data.end() ||  data[depth] < root->val){
            data[depth] = root->val;
         }
        if (root->left){
            dfs(root->left,depth + 1);
        }
        if (root->right){
            dfs(root->right, depth + 1);
        }
    }
    
    vector<int> largestValues(TreeNode* root) {
        if (!root) return ret;
        dfs(root, 1);        
        for(auto& p : data){
            ret.push_back(p.second);
        }
        return ret;
    }
};