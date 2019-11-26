// Description
// 中文
// English
// Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

// Each element is either an integer, or a list -- whose elements may also be integers or other lists.

// Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input: nestedList = [[1,1],2,[1,1]]
// Output: 8
// Explanation:
// four 1's at depth 1, one 2 at depth 2
// Example 2:

// Input: nestedList = [1,[4,[6]]]
// Output: 17
// Explanation:
// one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17


class Solution {
public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
     int depth(const vector<NestedInteger>& nestedList){
         if (nestedList.size() == 0) return 0;
         int d = 1;
         for(auto& v : nestedList){
             if (v.isInteger() == false){
                 d = max(1 + depth(v.getList()));
             }
         }
         return d;
     }
     
     int getSum(const vector<NestedInteger>& nestedList, int d){
            int sum = 0;
            for(auto& v : nestedList){
                if (v.isInteger()){
                    sum += v.getInteger() * d;
                }else{
                    sum += getSum(v.getList(), d  - 1);   
                }
            }    
            return sum;
     }
     
    int depthSumInverse(vector<NestedInteger> nestedList) {
        //get depth of list firstly
        int d = depth(nestedList);
        return getSum(nestedList,d);
    }
};