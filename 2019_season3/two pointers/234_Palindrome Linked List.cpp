// https://leetcode.com/problems/palindrome-linked-list/description/

// 234. Palindrome Linked List
// DescriptionHintsSubmissionsDiscussSolution
// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

// if we allow to change the linked list, we can divide the list into two parts
// first half part and second harlf part,
// and then we reverse the second half part of linked list
// then we just compare two linked list and check if each node has same value 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* node){
        if (node == nullptr || node->next == nullptr) return node;
        ListNode* t = node->next;
        ListNode* n = reverse(node->next);
        t->next = node;
        node->next = nullptr;
        return n;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        
        //1->2->2->1
        //two pointers
        //1->2, 第二个链表，2->1, 做一个翻转 1->2; 然后比较就可；
        //中点位置，分为两个链表，第二个链表做一个翻转
        //这样可以节省space
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow now is in the middle
        ListNode* secondHead = slow->next;
        slow->next = nullptr;
        
        //reverse the second list
        ListNode* p1 = reverse(secondHead);
        
        while(head && p1){
            if (head->val == p1->val){
                head = head->next;
                p1 = p1->next;
            }else{
                return false;
            }
        }
        return true;
    }
};
