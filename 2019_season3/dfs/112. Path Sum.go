


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var found bool

func helper(node *TreeNode, cur, sum int) {
	if found || node == nil {
		return
	}

	cur += node.Val
	if node.Left == nil && node.Right == nil {
		if cur == sum {
			found = true
		}
		return
	}
	helper(node.Left, cur, sum)
	helper(node.Right, cur, sum)
}

func hasPathSum(root *TreeNode, sum int) bool {
	found = false
	helper(root, 0, sum)
	return found
}



//path sum II

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
		
		
		vector<vector<int>> ret;
		
		void helper(TreeNode* node, vector<int> r,int sum){
			if (node == nullptr) return;
			r.push_back(node->val);
			if (node->left == nullptr && node->right == nullptr){
				int tmp = 0;
				for(auto&v : r) tmp += v;
				if (tmp == sum) ret.push_back(r);
				return;
			}
			helper(node->left,r,sum);
			helper(node->right,r,sum);
		}
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			vector<int> r;
			helper(root,r,sum);
			return ret;
		}
	};



	//引用的方式更加节省 space
	//dfs 引用vector 需要注意backtrack. 回溯

		//root->left , 需要回溯， root, 然后再 root->right

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
		
		
		vector<vector<int>> ret;
		
		void helper(TreeNode* node, vector<int>& r,int sum){
			if (node == nullptr) return;
			r.push_back(node->val);
			if (node->left == nullptr && node->right == nullptr){
				int tmp = 0;
				for(auto&v : r) tmp += v;
				if (tmp == sum) ret.push_back(r);
				return;
			}
			

			//引用的方式更加节省 space
			//dfs 引用vector 需要注意backtrack. 回溯
			//root->left , 需要回溯， root, 然后再 root->right
			//需要增加非空判断
			if (node->left){
				helper(node->left,r,sum);
				r.pop_back();
			}
			
			if (node->right){
				helper(node->right,r,sum);
				r.pop_back();
			}
		}
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			vector<int> r;
			helper(root,r,sum);
			return ret;
		}
	};