


// 559. Maximum Depth of N-ary Tree
// DescriptionHintsSubmissionsDiscussSolution
// Given a n-ary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// For example, given a 3-ary tree:

 


 

// We should return its max depth, which is 3.

 

// Note:

// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.



//BFS 基本的层级遍历

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        //bfs or dfs are ok
        
        int ret = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            ret++;
            
            //level traverse
            int size = q.size();
            
            for(int i =0; i < size; i++){
                auto n = q.front(); q.pop();

                for(auto v : n->children){
                    q.push(v);
                }
            }
        }
        return ret;
    }
};

//Recursively DFS 调用的方法

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    int helper(Node* root){
        if (!root) return 0;
        
        int d = 1;
        for(auto n : root->children){
            int t = helper(n);
            d = max(d, 1 + t);
        }
        return d;
    }
    
    int maxDepth(Node* root) {
        if (!root) return 0;
        return helper(root);
    }
};