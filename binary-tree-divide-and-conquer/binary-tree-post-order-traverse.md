---
description: 'https://www.lintcode.com/problem/binary-tree-postorder-traversal/description'
---

# Binary tree post order traverse

#### Description

Given a binary tree, return the postorder traversal of its nodes' values.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given binary tree `{1,#,2,3}`,

```text
   1
    \
     2
    /
   3
```

return `[3,2,1]`.

#### Challenge

Can you do it without recursion?

#### Related Problems

[66. Binary Tree Preorder Traversal](https://www.lintcode.com/problem/binary-tree-preorder-traversal)

```text
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

    void helper(vector<int>& res, TreeNode* root){
        if (root == nullptr) return;
        if (root->left){
            helper(res,root->left);
        }
        
        if (root->right){
            helper(res,root->right);
        }
        res.push_back(root->val);
    }
    
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        // write your code here
        // root, left, right preorder
        // left root, right inorder
        //left, right , root postorder
        vector<int> res;
        helper(res,root);
        return res;
    }
};
```

None recursive way is a little more difficult, 

```cpp
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
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> result;
        stack<TreeNode *> myStack;
        
        TreeNode *current = root, *lastVisited = NULL;
        while (current != NULL || !myStack.empty()) {
            while (current != NULL) {
                myStack.push(current);
                current = current->left;
            }
            current = myStack.top(); 
            if (current->right == NULL || current->right == lastVisited) {
                myStack.pop();
                result.push_back(current->val);
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }
        return result;
    }
};
```



