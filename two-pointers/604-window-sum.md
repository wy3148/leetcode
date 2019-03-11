# 604 window sum

Description

Given an array of n integers, and a moving window\(size k\), move the window at each iteration from the start of the array, find the `sum` of the element inside the window at each moving.Have you met this question in a real interview?  YesProblem Correction

#### Example

**Example 1**

```text
Input：array = [1,2,7,8,5], k = 3
Output：[10,17,20]
Explanation：
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20

```

```go
/**
 * @param nums: a list of integers.
 * @param k: length of window.
 * @return: the sum of the element inside the window at each moving.
 */
func winSum (nums []int, k int) []int {
    // write your code here
    
    ret := make([]int,0)
    if len(nums) < k || k <= 0{
        return ret
    }
    
    sum := 0
    for i := 0; i < k; i++{
        sum += nums[i]
    }
    ret = append(ret,sum)
    
    i := 0 
    j := k
    
    for i < len(nums) && j <len(nums){
        sum = sum - nums[i] + nums[j]
        i++
        j++
        ret = append(ret,sum)
    }
    
    return ret 
}

```



