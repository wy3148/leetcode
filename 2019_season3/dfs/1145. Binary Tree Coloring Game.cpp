// 1145. Binary Tree Coloring Game
// DescriptionHintsSubmissionsDiscussSolution
// Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.

// Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x.  The first player colors the node with value x red, and the second player colors the node with value y blue.

// Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

// If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

// You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it is not possible, return false.

 

// Example 1:


// Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
// Output: true
// Explanation: The second player can choose the node with value 2.
 

// Constraints:

// root is the root of a binary tree with n nodes and distinct node values from 1 to n.
// n is odd.
// 1 <= x <= n <= 100





// the idea, find the node with value x firstly, 

// then get number of its child nodes, there are three difference cases then,
//  node x has less than half nodes in total, so second node y can take a place on the other side

// node x has more than half nodes, but left or right child tree has more than half, in this case
// second node can take one place in its child node,


/*
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
    
    //find the node of x value
    TreeNode* find(TreeNode* root, int x){
        if (!root) return root;
        if (root->val ==x) return root;
        TreeNode* l = find(root->left,x);
        TreeNode* r = find(root->right,x);
        return l == nullptr ? r : l;
    }
    
    int numberofNodes(TreeNode* node){
        if (!node) return 0;
        return 1 + numberofNodes(node->left) + numberofNodes(node->right);
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        TreeNode*  first = find(root, x);
        if (!first) return false;
        int count = numberofNodes(first);
        int c1 =  numberofNodes(first->left);
        int c2 = count - c1
        
        if (n - count > n / 2  || c1 > n/ 2 || c2 > n /2) return true;
        return false;        
    }
};

