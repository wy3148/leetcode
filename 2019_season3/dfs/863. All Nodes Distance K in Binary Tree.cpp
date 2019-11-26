// 863. All Nodes Distance K in Binary Tree


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
    
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    
    void buildGraph(TreeNode* root){
        if (!root) return;
        if (root->left){
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            buildGraph(root->left);
        }
        if (root->right){
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            buildGraph(root->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        vector<int> ans;
        if (!root || !target) return ans;
        
        //graph, steps
        //first, build up a graph, node- all his neighbor nodes
        //
        buildGraph(root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        
        int d = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* n = q.front(); q.pop();
                if (d  == K){
                    ans.push_back(n->val);
                }
                
                //可能会重复访问的结点，需要用visited 标识
                for(TreeNode* node : graph[n]){
                    if (visited.find(node) == visited.end()){
                        q.push(node);
                        visited.insert(node);
                    }
                }
            }
            d++;
        }
        return ans;
    }
};


/// DFS
