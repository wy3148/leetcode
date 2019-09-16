//https://www.lintcode.com/problem/convert-binary-tree-to-doubly-linked-list/description

// Back
// 378. Convert Binary Tree to Doubly Linked List
// Description
// English
// Convert a binary tree to doubly linked list with in-order traversal.

// Have you met this question in a real interview?  
// Example
// Example 1：

// Input:
// 	    4
// 	   / \
// 	  2   5
// 	 / \
// 	1   3		

// Output: 1<->2<->3<->4<->5
// Example 2：

// Input:
// 	    3
// 	   / \
// 	  4   1

// Output:4<->3<->1

/**
  * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
 *         this->prev = this->next = NULL;
 *     }
 * } * Definition of TreeNode:
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
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode * bstToDoublyList(TreeNode * root) {
        DoublyListNode* head = nullptr;
        DoublyListNode* prev = nullptr;
        if (root == nullptr) return head;
        
        std::stack<TreeNode*> s;
        TreeNode* n = root;
        while(n || !s.empty()){
            while(n){
                s.push(n);
                n = n->left;
            }
            
            TreeNode* node = s.top(); s.pop();
            DoublyListNode* t = new DoublyListNode(node->val);            
            if (prev){
                prev->next = t;
                t->prev = prev;
                prev = t;
            }else{
                prev = t;
            }
            
            if (!head){
                head = t;
            }
            
            if (node){
                n = node->right;
            }
        }
        return head;
    }
};
