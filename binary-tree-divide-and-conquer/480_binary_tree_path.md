---
description: 'https://www.lintcode.com/problem/binary-tree-paths/description'
---

# 480 binary tree path

Note:

all the binary tree path, should be the basic of dfs

#### Description

Given a binary tree, return all root-to-leaf paths.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input:

   1
 /   \
2     3
 \
  5

Output:


[
  "1->2->5",
  "1->3"
]
```

Example 2:

```text
Input:

   1
 /   
2     
 

Output:


[
  "1->2"
]

```

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

    void dfs(TreeNode* node, vector<string>& res, string cur){
        if (node == nullptr) return;
        
        if (cur.length() == 0){
            cur += to_string(node->val);
        }else{
            cur += "->" + to_string(node->val);
        }
        
        if (node->left == nullptr && node->right == nullptr){
            res.push_back(cur);
        }
        dfs(node->left,res,cur);
        dfs(node->right,res,cur);
    }


    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        vector<string> res;
        string cur;
        dfs(root,res,cur);
        return res;
    }
};
```

