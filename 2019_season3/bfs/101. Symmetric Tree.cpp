

// 101. Symmetric Tree
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
 

// But the following [1,2,2,null,3,null,3] is not:

//     1
//    / \
//   2   2
//    \   \
//    3    3
 

// Note:
// Bonus points if you could solve it both recursively and iteratively

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
    
    bool isSymmetric(TreeNode* node1, TreeNode* node2){
        if (node1 == nullptr &&  node2 != nullptr || node1 != nullptr && node2 == nullptr){
            return false;
        }
        if (node1 == nullptr && node2 == nullptr) return true;
        
        if (node1->val != node2->val){
            return false;
        }
        
        return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
};

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<TreeNode*> tmp;
            for(int c = 0; c < size;c++){
                TreeNode* n  = q.front(); q.pop();
                tmp.push_back(n);
                if (n != nullptr){
                    q.push(n->left);
                    q.push(n->right);
                }
            }
            
            if (tmp.size() == 0){
                continue;
            }
            
            int l = 0; int r = tmp.size() - 1;
            while(l < r){
                
                if (tmp[l]  != nullptr && tmp[r] != nullptr){
                    if (tmp[l]->val != tmp[r]->val) return false;
                }else if (tmp[l] && tmp[r] == nullptr || tmp[l] == nullptr && tmp[r]){
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};
