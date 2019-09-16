// Description
// English
// Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

// A valid path is from root node to any of the leaf nodes.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input:
// {1,2,4,2,3}
// 5
// Output: [[1, 2, 2],[1, 4]]
// Explanation:
// The tree is look like this:
// 	     1
// 	    / \
// 	   2   4
// 	  / \
// 	 2   3
// For sum = 5 , it is obviously 1 + 2 + 2 = 1 + 4 = 5
// Example 2:

// Input:
// {1,2,4,2,3}
// 3
// Output: []
// Explanation:
// The tree is look like this:
// 	     1
// 	    / \
// 	   2   4
// 	  / \
// 	 2   3
// Notice we need to find all paths from root node to leaf nodes.
// 1 + 2 + 2 = 5, 1 + 2 + 3 = 6, 1 + 4 = 5 
// There is no one satisfying it.
// Related Problems



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

    void dfs(TreeNode* root, vector<vector<int>>& result, vector<int>& ret, int cur,int target){
        if (root == nullptr) return;
        
        ret.push_back(root->val);
        
        //got the target and current node is leaf node 
        if (root->val + cur == target && root->left == nullptr && root->right == nullptr){
            result.push_back(ret);
            return;
        }
        
        //Warning:数组ret，保存遍历的int的时候， 如果是用的
        //reference， 需要backtracking，可以节省内存空间 避免内存拷贝
        //每一个对应的if condition 都需要做pop_back()
        //
        if (root->left){
            dfs(root->left,result,ret, cur + root->val, target);
            ret.pop_back();
        }
        
        if (root->right){
            dfs(root->right,result,ret, cur + root->val, target);
            ret.pop_back();
        }
    }
    
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        vector<vector<int>> result;
        vector<int> ret;
        if (root == nullptr) return result;
        
        dfs(root, result,ret,0,target);
        return result;
    }
};


//binary tree path sum
//问题有几类情况，简单的时候从root到叶子结点所有的path sum
//第二种是 任意一个结点到其他任何结点的path sum， 难度就会提升很多

//https://www.lintcode.com/problem/binary-tree-path-sum-ii/description


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
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        if (!root) return vv;
        vector<int> v;
        helper(root, target, v);
        return vv;
    }

private:
    vector<vector<int>> vv;
    void helper(TreeNode * root, int target, vector<int> & v) {
        if (!root) return;

        v.push_back(root->val);

        int sum = 0, n = v.size();
        for (int i = n - 1; i >= 0; --i) {
            sum += v[i];
            if (sum == target) {
                vv.push_back(vector<int>(v.begin() + i, v.end()));
            }
                
        }
        
        helper(root->left, target, v);
        helper(root->right, target, v);

        v.pop_back();
    }
};


//需要分享下面的代码为什么有bug， 重复计算了最后的结点
//Bug!!!!!!Warning

class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& result, vector<int> tmp,
    int cur, int target){
        if (root == nullptr) return;
        
        if (root->val + cur == target){
            tmp.push_back(root->val);
            result.push_back(tmp);
        }else{
            tmp.push_back(root->val);
            dfs(root->left,result,tmp,cur + root->val, target);
            dfs(root->right,result,tmp,cur + root->val, target);
        }
        

        //这里有重复计算
        vector<int> t;
        dfs(root->left,result,t,0, target);
        dfs(root->right,result,t,0, target);
    }
    
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(root,result,tmp,0, target);
        return result;
    }
};

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



//下面这种思路，有大量重复计算的过程，复杂度过高; helper的时间复杂度是O(n);
//binaryTreePathSum2 又调用了n次， 总的时间复杂度是 n * n 
class Solution {
public:

    vector<vector<int>> result;
    
    void helper(TreeNode* root, vector<int> tmp, int cur, int target){
        
        if (root == nullptr) return;
        
        tmp.push_back(root->val);
        if (root->val + cur == target){
            result.push_back(tmp);
        }
        
        helper(root->left,tmp, cur + root->val,target);
        helper(root->right,tmp, cur + root->val,target);
    }
    
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        
        if (root == nullptr) return result;
        vector<int> tmp;
        
        helper(root, tmp, 0, target);
        binaryTreePathSum2(root->left,target);
        binaryTreePathSum2(root->right, target);
        return result;
    }
};

