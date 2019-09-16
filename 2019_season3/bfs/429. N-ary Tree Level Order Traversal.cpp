// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example, given a 3-ary tree:

 



 

// We should return its level order traversal:

// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
 

// Note:

// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.

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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>ret;
        if (!root) return ret;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()){
            
            vector<int> cur;
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto n = q.front(); q.pop();
                cur.push_back(n->val);
                for(auto c :n->children){
                    q.push(c);
                }
            }
            ret.push_back(cur);
        }
        return ret;
    }
};
