# Inorder successor of BST tree node

#### Description

中文English

Given a binary search tree \([See Definition](http://www.lintcode.com/problem/validate-binary-search-tree/)\) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return `null`.

It's guaranteed _p_ is one node in the given tree. \(You can directly compare the memory address to find p\)Have you met this question in a real interview?  YesProblem Correction

#### Example

Given tree = `[2,1]` and node = `1`:

```text
  2
 /
1
```

return node `2`.

Given tree = `[2,1,3]` and node = `2`:

```text
  2
 / \
1   3
```

return node `3`.

#### Challenge

O\(h\), where h is the height of the BST.

```cpp
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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        
        if (root == nullptr || p == nullptr) return nullptr;

        if ( root->val <= p->val){
            return inorderSuccessor(root->right,p);
        }
        
        TreeNode* left = inorderSuccessor(root->left,p);
        return left == nullptr ? root : left;
    }
};
```

my answer which is not best:

```cpp
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

    void inorder(std::vector<TreeNode*>& res,TreeNode* root){
        if (root == nullptr) return;
        
        if (root->left){
            inorder(res, root->left);
        }
        
        res.push_back(root);
        
        if (root->right){
            inorder(res, root->right);
        }
    }

    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
            if (root == nullptr || p == nullptr) return nullptr;
            
            vector<TreeNode*> res;
            inorder(res,root);
            
            int start = 0;
            int end =  res.size() - 1; 
            
            while (start + 1 < end){
                int mid = (end - start) / 2 + start;
                if (p->val  == res[mid]->val){
                    return res[mid + 1];
                }else if (p->val > res[mid]->val){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
            if (res[start]->val == p->val && start + 1 < res.size()){ return res[start + 1];
            }
            
            if (res[end]->val == p->val && end + 1 < res.size()){ return res[end + 1];
            }
            return nullptr;
    }
};
```

another way, during the process of inorder traverse, we record the 'resulType' 

```cpp
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
        TreeNode* successor;
        bool found ;
        Result(TreeNode* n, bool f){
            successor = n;
            found = f;
        }
    };

    void inorder(TreeNode* root, TreeNode* p,Result& r ){
        if (root  == nullptr) return;
        
        inorder(root->left,p,r);
        
        //only when the p is found ,and successor
        //is still null, we set the successor now
        if (r.found && r.successor == nullptr){
            r.successor = root;
            return;
        }else if(root == p){
            r.found = true;
        }
        
        inorder(root->right,p,r);
    }
    
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        Result r(nullptr,false);
        inorder(root,p,r);
        return r.successor;
    }
};
```

