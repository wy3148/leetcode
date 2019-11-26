// 105. Construct Binary Tree from Preorder and Inorder Traversal
// DescriptionHintsSubmissionsDiscussSolution
// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7


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
    
    //dfs build, the inorder is acutally used to get the postion of root node every time
    //this hard part is to define this dfs/recursive function
    TreeNode* build(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend){
        if (pstart > pend || istart > iend) return nullptr;
        
        //root node
        TreeNode* node = new TreeNode(preorder[pstart]);
        
        //find pos in inorder for this root node
        int pos = - 1;
        for (int i = istart; i <= iend; i++){
            if (inorder[i] == preorder[pstart]){
                pos = i;
                break;
            }
        }
        //数组一分为二；左边测和右边测；
        //pos is the root, it wont' be included anyway
        //pstart + pos - istart represent how many nodes are from left
        node->left = build(preorder,pstart + 1, pstart + pos - istart, inorder,istart,pos - 1);
        node->right = build(preorder,pstart +  pos - istart + 1, pend, inorder, pos + 1, iend);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        return build(preorder,0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};



