---
description: 'https://www.lintcode.com/problem/maximum-subarray/description'
---

# 41. Maximum Subarray

#### Description

中文English

Given an array of integers, find a contiguous subarray which has the largest sum.

The subarray should contain at least one number.Have you met this question in a real interview?  YesProblem Correction

#### Example

**Example1:**  
Given the array `[−2,2,−3,4,−1,2,1,−5,3]`, the contiguous subarray `[4,−1,2,1]` has the largest sum = `6`.  
**Example2:**  
Given the array `[1,2,3,4]`, the contiguous subarray `[1,2,3,4]` has the largest sum = `10`.

#### Challenge

Can you do it in time complexity O\(n\)?

```text
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        
        if (nums.size() == 0) return 0;
        int res = 0;
        int maxRes = INT_MIN;
        
        
        //start from 0,
        //logic: if we add an element, sum is negative,
        //we start from 0 again, assume previous subarray is invalid
        //to get maximum value
        for(int i = 0; i < nums.size(); i++){
            res += nums[i];
            maxRes = maxRes < res ? res : maxRes;
            if (res < 0){
                res = 0;
            }
        }
        return maxRes;
    }
};
```



```text
/**
 * @param nums: A list of integers
 * @return: A integer indicate the sum of max subarray
 */

import "math"
    
func maxSubArray (nums []int) int {
    // write your code here
    tmp := 0
    res := math.MinInt32
    
    for i:= 0; i < len(nums); i++{
        tmp += nums[i]
        if tmp > res{
            res = tmp
        }
        
        if tmp < 0 {
            tmp = 0
        }
    }
    return res
}

```

