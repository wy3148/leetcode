


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    
    struct Result{
        bool hasA;
        bool hasB;
        TreeNode* node;
        Result(bool a, bool b,TreeNode* n){
            node = n;
            hasA = a;
            hasB = b;
        }
    };
    
    Result helper(TreeNode* root, TreeNode* A, TreeNode* B){
        if (root == nullptr){
            return Result(false,false,nullptr);
        }
        
        //left subtree, right subtree 
        Result l = helper(root->left,A, B);
        Result r = helper(root->right,A,B);
        
        bool localHasA  = false;
        bool localHasB = false;
        if (l.hasA || r.hasA || root == A ){
            localHasA = true;
        }
        if (l.hasB || r.hasB || root == B){
            localHasB = true;
        }
        
        if (root == A || root == B){
            return Result(localHasA,localHasB,root);
        }
        
        if (l.node && r.node){
            return Result(localHasA,localHasB,root);
        }
        if (l.node){
            return Result(localHasA,localHasB,l.node);     
        }
        if (r.node){
            return Result(localHasA,localHasB,r.node);     
        }
        return Result(localHasA,localHasB,nullptr);
    }
    
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        Result r = helper(root,A,B);
        if(r.hasA && r.hasB){
            return r.node;
        }
        return nullptr;
    }
};

