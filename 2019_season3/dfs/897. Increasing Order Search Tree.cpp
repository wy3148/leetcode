// 897. Increasing Order Search Tree
// DescriptionHintsSubmissionsDiscussSolution
// Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

// Example 1:
// Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

//        5
//       / \
//     3    6
//    / \    \
//   2   4    8
//  /        / \ 
// 1        7   9

// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

//  1
//   \
//    2
//     \
//      3
//       \
//        4
//         \
//          5
//           \
//            6
//             \
//              7
//               \
//                8
//                 \
//                  9  
// Note:

// The number of nodes in the given tree will be between 1 and 100.
// Each node will have a unique integer value from 0 to 1000.




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


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
    
    void dfs(TreeNode* root, vector<TreeNode*>& data){
        if (root == nullptr) return;
        dfs(root->left,data);
        data.push_back(root);
        dfs(root->right,data);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        //inorder: left root, right
        if (root == nullptr) return nullptr;
        vector<TreeNode*> data;
        dfs(root,data);
        TreeNode* prev = nullptr;
        for(int i = 0; i < data.size(); i++){
            if (i == 0){
                prev = data[i];
                prev->left = nullptr;
            }else{
                prev->right = data[i];
                prev = data[i];
                prev->left = nullptr;
            }
        }
        return data[0];
    }
};




//inorder的非递归使用


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
    TreeNode* increasingBST(TreeNode* root) {
        //inorder 非遍历方法调用？
        //inorder; left root, right
        TreeNode* prev = nullptr;
        TreeNode* newRoot = nullptr;
        stack<TreeNode*> data;
        
        while(root){
            data.push(root);
            root = root->left;
        }
        
        while(!data.empty()){
            
            auto n = data.top(); data.pop();
            
            if (!newRoot){
                newRoot = n;
                prev = n;
                prev->left = nullptr;
            }else{
                prev->right = n;
                prev = n;
                prev->left = nullptr;
            }
            
            TreeNode* r = n->right;
            while(r){
                data.push(r);
                r = r->left;
            }
        }
        return newRoot;
    }
};
