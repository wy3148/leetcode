# 585 maximum number in mountain



#### Description

Given a mountain sequence of `n` integers which increase firstly and then decrease, find the mountain top.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input: nums = [1, 2, 4, 8, 6, 3] 
Output: 8
```

Example 2:

```text
Input: nums = [10, 9, 8, 7], 
Output: 10
```

Note:

start + 1 &lt; end

when exit the loop, we have two elements left, we return the bigger one.



```cpp
/**
 * @param nums: a mountain sequence which increase firstly and then decrease
 * @return: then mountain top
 */
func mountainSequence (nums []int) int {
    // write your code here
    
    if len(nums) == 0 {
        return 0
    }
    
    start := 0
    end := len(nums) - 1
    
    for start + 1 < end{
        
        mid := start + (end - start) / 2 
        
        if nums[mid] > nums[mid- 1] && nums[mid] > nums[mid + 1]{
            return nums[mid]
        }else if nums[mid] > nums[mid - 1]{
            start = mid
        }else{
            end = mid
        }
    }
    
    if nums[start] > nums[end] {
        return nums[start]
    }
    return nums[end]
}

```





