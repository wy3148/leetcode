



// https://www.lintcode.com/problem/nested-list-weight-sum/description

// 551. Nested List Weight Sum
// This is the problem you have done. Do you remember how to solve it?
// Description
// 中文
// English
// Given a nested list of integers, return the sum of all integers in the list weighted by their depth. Each element is either an integer, or a list -- whose elements may also be integers or other lists.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input: the list [[1,1],2,[1,1]], 
// Output: 10. 
// Explanation:
// four 1's at depth 2, one 2 at depth 1, 4 * 1 * 2 + 1 * 2 * 1 = 10
// Example 2:

// Input: the list [1,[4,[6]]], 
// Output: 27. 
// Explanation:
// one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4 * 2 + 6 * 3 = 27




/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */



//基本的dfs思路，定义一个递归函数，判断递归函数返回的条件；
class Solution {
public:
    int dfs(const vector<NestedInteger>& nestedList, int depth){
        int sum = 0;
        for(auto& v : nestedList){
            if (v.isInteger()){
                sum += v.getInteger() * depth;
            }else{
                sum += dfs(v.getList(), depth + 1);
            }
        }
        return sum;
    }
    
    int depthSum(const vector<NestedInteger>& nestedList) {
        // Write your code here
        if (nestedList.size() == 0) return 0;
        int depth =1;
        return dfs(nestedList,depth);
    }
};

