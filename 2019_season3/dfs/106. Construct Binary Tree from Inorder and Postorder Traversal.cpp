

// 106. Construct Binary Tree from Inorder and Postorder Traversal
// DescriptionHintsSubmissionsDiscussSolution
// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7


//The basic idea is to use DFS,define a recursive function, with [start,end] position information
//for each array

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
    
    TreeNode* setup(vector<int>& inorder, vector<int>& postorder,int istart, int iend, int pstart, int pend){
        //inorder, left, root ,right
        //postorder, left , right , root        
        if (istart > iend) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[pend]);
        int pos = -1;
        for(int i = istart; i <= iend; i++){
            if (inorder[i] == postorder[pend]){
                pos = i;
                break;
            }
        }
        
        //[9,3,15,20,7]  pos = 1, istart = 0; pos - istart =1;
        //[9,15,7,20,3]
        
        //the key point is get the pos - istart + 1 part, 
        //找到root点的位置，然后确认root的left subtree的child nodes数量就可以
        root->left = setup(inorder,postorder,istart, pos - 1, pstart, pstart + pos - istart - 1);
        root->right = setup(inorder,postorder,pos + 1, iend, pstart + pos - istart,pend - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return setup(inorder,postorder,0, inorder.size() - 1,0,postorder.size() - 1);
    }
};



//Go version

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */


func setup(inorder []int, istart,iend int, postorder[]int, pstart, pend int) *TreeNode{
    if istart > iend{
        return nil
    }
    
    node := &TreeNode{
        Val: postorder[pend],
    }
    
    pos := -1
    for pos = istart; pos <= iend; pos++{
        if inorder[pos] == postorder[pend]{
            break
        }
    }
    
    node.Left =  setup(inorder, istart, pos - 1, postorder, pstart, pstart + pos - istart - 1)
    node.Right = setup(inorder, pos + 1, iend, postorder, pstart + pos - istart, pend - 1)
    return node
}

func buildTree(inorder []int, postorder []int) *TreeNode {
    return setup(inorder,0, len(inorder) - 1, postorder, 0, len(postorder) - 1)
}
