# Binary tree maximum path sum



#### Description

中文English

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
Example 1:
	Input:  For the following binary tree（only one node）:
	2
	Output：2
	
Example 2:
	Input:  For the following binary tree:

      1
     / \
    2   3
		
	Output: 6
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
    int ret;

    int helper(TreeNode* root){
        if (root == nullptr) return 0;
        
        int sum = root->val;
        int l= 0;
        int r = 0;
        
        //divide and conquer, left subtree value
        //right subtree, if both are postive value
        // plus current root node
        l = helper(root->left);
        r = helper(root->right);
        
        if (l > 0){
            sum += l;
        }
        if (r > 0){
            sum += r;
        }
        
        ret = max(ret,sum);
        
        //always returns a single path which has bigger value
        //left path, or right path//
        
        return max(0,max(l,r) + root->val);
    }

    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        // write your code here
        if (root == nullptr) return 0;
        
        ret = INT_MIN;
        helper(root);
        return ret;
    }
};
```

Given a binary tree, find the maximum path sum from root.

The path may end at any node in the tree and contain at least one node in it.

```java

public class Solution {
    /**
     * @param root the root of binary tree.
     * @return an integer
     */
    public int maxPathSum2(TreeNode root) {
        if (root ==  null) {
            return Integer.MIN_VALUE;
        }
        
        int left = maxPathSum2(root.left);
        int right = maxPathSum2(root.right);
        
        return root.val + Math.max(0, Math.max(left, right));
    }

```



