
// 1026. Maximum Difference Between Node and Ancestor
// DescriptionHintsSubmissionsDiscussSolution
// Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

// (A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

// Example 1:



// Note:

// The number of nodes in the tree is between 2 and 5000.
// Each node will have value between 0 and 100000.

// Input: [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: 
// We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.



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
    

    
    int ans;

    Solution(){
        ans = INT_MIN;
    }
    
    void dfs(int cur, TreeNode* left, TreeNode* right){
        if (left){
            ans = max(ans, abs(left->val - cur));
            dfs(cur,left->left,left->right);
        }
        
        if (right){
            ans = max(ans, abs(right->val- cur));
            dfs(cur,right->left,right->right);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        dfs(root->val, root->left, root->right);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return ans;
    }
};
