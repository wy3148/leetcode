// 993. Cousins in Binary Tree
// DescriptionHintsSubmissionsDiscussSolution
// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

// Return true if and only if the nodes corresponding to the values x and y are cousins.

 

// Example 1:


// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:


// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:



// Input: root =- [1,2,3,null,4], x = 2, y = 3
// Output: false
 

// Note:

// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.


//第一反应是DFS的算法//由上至下
//一层一层往下 直到找到了node x, y

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
    
    struct Result{
        TreeNode* parent;
        int depth;
        Result(TreeNode* n , int d){
            parent = n;
            depth = d;
        }
    };
    
    Result find(TreeNode* p, TreeNode* root, int val, int d){
        if (root == nullptr){
            return Result(nullptr,0);
        }
        if (root->val == val){
            return Result(p,d + 1);
        }
        Result l = find(root,root->left,val, d + 1);
        Result r = find(root,root->right,val, d + 1);
        if (l.parent != nullptr) return l;
        return r;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        Result r1 = find (nullptr, root, x, 0);
        Result r2 = find (nullptr, root, y, 0);
        if (r1.depth == r2.depth && r1.parent != r2.parent){
            return true;
        }
        return false;
    }
};



//BFS 层级遍历可以实现，寻找当前root的子结点是否是目标结点，
//如果是返回结果

//不管哪一种实现方式，定义一个Result struct 包含parent node信息和
//depth 信息

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
    
    struct Result{
        TreeNode* parent;
        int depth;
        Result(TreeNode* n , int d){
            parent = n;
            depth = d;
        }
    };
    
    // Result find(TreeNode* p, TreeNode* root, int val, int d){
    //     if (root == nullptr){
    //         return Result(nullptr,0);
    //     }
    //     if (root->val == val){
    //         return Result(p,d + 1);
    //     }
    //     Result l = find(root,root->left,val, d + 1);
    //     Result r = find(root,root->right,val, d + 1);
    //     if (l.parent != nullptr) return l;
    //     return r;
    // }
    
    Result find(TreeNode* root, int val){
        queue<TreeNode*> q;
        if (root == nullptr){
            return Result(nullptr,0);
        }
        
        int d = 0;
        q.push(root);
        while(!q.empty()){
            
            int size = q.size();
            d++;
            
            for(int i = 0; i < size; i++){
                TreeNode* n = q.front(); q.pop();
                
                if (n->left && n->left->val == val){
                    return Result(n,d + 1);
                }
                
                if (n->right && n->right->val == val){
                    return Result(n,d + 1);
                }
                
                if (n->left){
                    q.push(n->left);
                }
                if (n->right){
                    q.push(n->right);
                }
            }
        }
        
        //val does not exist in the tree
        return Result(nullptr,0);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        // Result r1 = find (nullptr, root, x, 0);
        // Result r2 = find (nullptr, root, y, 0);
        
        Result r1 = find(root, x);
        Result r2 = find(root, y);
        
        if (r1.depth == r2.depth && r1.parent != r2.parent){
            return true;
        }
        return false;
    }
};
