


//the idea is to calculate the path sum to leaf node
//and we use extra hashmap data structure to record the node status
//a node can be removed only when node has no path to a sum which is
//bigger than limit

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
    
    //each node->value,
    //by default, default is 0;
    map<TreeNode*,int> sumInfo;
    
    void pathSum(vector<TreeNode*>& path,TreeNode* node, int cur, int limit){
        if (node== nullptr) return;
        
        path.push_back(node);
        cur += node->val;
        
        if (node->left == nullptr && node->right == nullptr){
            if (cur < limit){
                for(TreeNode* n : path){
                    
                    //if never set
                    if (sumInfo[n] == 0){
                        sumInfo[n] = -1;
                    }
                }
            }else{
                for(TreeNode* n : path){
                    
                    //this node is suffient
                     sumInfo[n] = 1;
                }                
            }
            return;
        }
        
        if (node->left){
            
            //path pop, backtrack
            pathSum(path,node->left, cur, limit);
            path.pop_back();
        }
        
        if (node->right){
            pathSum(path,node->right,cur,limit);
            path.pop_back();
        }
    }
    
    void dfs(TreeNode* node, TreeNode* parent){
        if (node == nullptr) return;
        if (sumInfo[node] < 0 ){            
            if (parent && parent->left == node) parent->left = nullptr;
            if (parent && parent->right == node) parent->right = nullptr;
        }
        
        
        //every node needs to be visited, regarldess current node is being removed or not
        if (node->left){
            dfs(node->left, node);
        }
        if (node->right){
            dfs(node->right,node);
        }
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        vector<TreeNode*> cur;
        pathSum(cur,root,0,limit);
        dfs(root, nullptr);
        
        if (sumInfo[root] < 0 ) return nullptr;
        return root;
    }
};