---
description: >-
  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
---

# 34 Find First and Last Position of Element in Sorted Array



Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

Your algorithm's runtime complexity must be in the order of _O_\(log _n_\).

If the target is not found in the array, return `[-1, -1]`.

**Example 1:**

```text
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```text
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

```

Notes:

we can find the first position of the element which is less than the target number, then we start to iterator from the start position. 

```cpp
func searchRange(nums []int, target int) []int {
    
    var res []int
    
    if len(nums) == 0 || target < nums[0] || target > nums[len(nums) - 1]{
        res = append(res,-1,-1)
        return res
    }
    
    start := 0
    end := len(nums) - 1
    
    //1,2,4
    //target: 1,2,4,3,0
    //find the start position which the element is less than target number
    for start + 1 < end{
        mid := start + (end - start)/2
        if nums[mid] >= target{
            end = mid
        }else{
            start = mid
        }
    }
    
    prev := -1 
    for start < len(nums){
        if (nums[start] == target){
            prev = start
            if len(res) == 0{
                res = append(res,start)
            }
        }else if (nums[start] > target){
            break
        }
        start++
    }
    if len(res) == 0{
        res = append(res,-1,-1)
        return res
    }
    res = append(res,prev)
    return res
}
```

more simple code

```cpp
func searchRange(nums []int, target int) []int {
    if len(nums) == 0 {
        return []int{-1,-1}
    }
    
    var res []int
    
    start := 0
    end := len(nums) - 1
    
    for start + 1 < end{
        
        mid := (start + end) / 2
        
        if nums[mid] >= target{
            end = mid
        }else{
            start = mid
        }
    }
    
    for start < len(nums){
        if nums[start] == target{
            res = append(res,start)
            start++
        }else if nums[start] < target{
            start++
        }else{
            break
        }
    }
    
    if len(res) == 0{
        return []int{-1,-1}
    }
    return []int{res[0],res[len(res) - 1]}    
}
```

