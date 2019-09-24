
// 863. All Nodes Distance K in Binary Tree
//下面的算法是错误！！！！Warning!!!


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import "fmt"

var targetDepth int
func depth(root* TreeNode, target *TreeNode, cur int, found *bool){
    if root == nil || *found == true{
        return
    }
    if root == target{
        *found = true
        targetDepth = cur
        return
    }
    depth(root.Left,target,cur + 1,found)
    depth(root.Right,target,cur + 1,found)
}

func dist(node *TreeNode,target* TreeNode, K int) []int{
    if node == nil || target == nil || K < 0{
        return nil
    }
    
    if K == 0{
        return []int{node.Val}
    }
    
    var queue []*TreeNode
    queue = append(queue,node)
    var ret []int
    d := -1
    for len(queue) > 0 {
        d++
        size := len(queue)
        for i := 0; i < size; i++{
            node := queue[i]
            if d == K{
                ret = append(ret,node.Val)
            }
            if node.Left != nil  && node.Left != target {
                queue = append(queue,node.Left)
            }
            if node.Right != nil && node.Right != target{
                queue = append(queue,node.Right)
            }
        }
        queue = queue[size:]
        if d == K {
            break
        }
    }   
    return ret
}

func distanceK(root *TreeNode, target *TreeNode, K int) []int {
    if K == 0 {
        return []int{target.Val}
    }
    if root == nil || target == nil || K < 0 {
        return nil
    }
    
    //from target to child nodes
    ret := dist(target,target, K)
    
    if root != target{
        left := false
        right := false
        depth(root.Left, target,1,&left)
        depth(root.Right, target,1,&right)
        
        if K == targetDepth{
            ret = append(ret,root.Val)
            
            var r []int
            
            if left{
                r = dist(root.Left,target, K -1)   
            }            
 
            if right{
                r = dist(root.Right,target, K -1)   
            }   
            
            if r != nil{
                ret = append(ret,r...)
            }
            
            return ret
        }
        
        var r []int
        if K > targetDepth{
            //targetDepth + the other side of nodes
            if left{
                l := dist(root.Right,target, K-targetDepth - 1)
                if l != nil {
                    r = append(r,l...)
                }
            }
            
            if right{
                rr := dist(root.Left,target, K-targetDepth - 1)
                if rr != nil {
                    r = append(r,rr...)
                }
            }
        }else if left{
            r = dist(root.Left,target, targetDepth - K -1) 
        }else if right{
            r = dist(root.Right,target, targetDepth - K -1)    
        }
        if r != nil{
            ret = append(ret,r...)
        }
    }
    return ret
}



//正确的算法！！！！

//第一步， dfs 函数递归的方法建立graph undirected graph
//第二步， 从target结点出发，直接bfs找到距离为K的nodes


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
    
    unordered_map<TreeNode*, vector<TreeNode*>> g;
    
    void buildGraph(TreeNode* root ){
        if (root == nullptr) return;
        
        if (root->left){
            g[root].push_back(root->left);
            g[root->left].push_back(root);
        }
        
        if (root->right){
            g[root].push_back(root->right);
            g[root->right].push_back(root);
        }
        
        buildGraph(root->left);
        buildGraph(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(root);
        vector<int> ret;
        
        if (root == nullptr || target == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int d = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* n = q.front(); q.pop();
                if (d == K) ret.push_back(n->val);
                for(auto node : g[n]){
                    if (visited.find(node)  == visited.end()){
                      visited.insert(node);
                      q.push(node);
                    }
                }
            }
            d++;
        }
        return ret;
    }
};




//dfs的递归方法
//相对不难理解，但是递归函数不太好写， 需要根据dfs返回的三种不同结果做判断
//return 0, -1, > 0



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
    
    vector<int> ret;
    
    //return -1, target not in tree
    //return > 0, the distance
    int dfs(TreeNode* root, TreeNode* target, int K){
        
        if (root == nullptr) return -1;
        
        //当前node等于target,那么开始collect target的所有子结点距离为K的结点
        if (root == target){
            collectNodes(target, K);
            return 0;
        }
        
        int l = dfs(root->left, target, K);
        int r = dfs(root->right,target, K);
        
        //if target not equal to current root node, meaning target is on its child tree, left child
        //tree or right child tree, distance from root to target must be > 0
        if (l >= 0){
            if ( l == K -1 ) ret.push_back(root->val);
            //另外一测的结点 距离为 K - l - 2, 当前root 到target距离是 l + 1; 
            //所以总距离为K
            collectNodes(root->right, K  - l - 2);
            return l + 1;
        }
        
        if (r >= 0){
            if (r == K - 1 ) ret.push_back(root->val);
            collectNodes(root->left, K  - r - 2);
            return r + 1;            
        }
        return -1;
    }
    //from current node, try to collect nodes with correct distance
    void collectNodes(TreeNode* node, int d){
        if (node == nullptr || d < 0) return;
        if (d == 0){
            ret.push_back(node->val);
            return;
        }
        collectNodes(node->left,d -1);
        collectNodes(node->right, d - 1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == nullptr || target == nullptr) return {};
        dfs(root, target, K);
        return ret;
    }
};


