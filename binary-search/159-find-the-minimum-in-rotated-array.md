# Find the minimum in rotated array

#### Description

中文English

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

\(i.e., `0 1 2 4 5 6 7` might become `4 5 6 7 0 1 2`\).

Find the minimum element.

You may assume no duplicate exists in the array.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given `[4, 5, 6, 7, 0, 1, 2]` return `0`

#### Related Problems

Note:

we need to compare the middle node with the 0 node, figure out if the middle is rotated or not, then decide the start and end position on next loop.

```cpp
/**
 * @param nums: a rotated sorted array
 * @return: the minimum number in the array
 */
func findMin (nums []int) int {
    // write your code here
    if len(nums) == 0{
        return 0
    }
    
    start := 0
    end := len(nums) - 1
    
    //not rotated
    if nums[start] <= nums[end]{
        return nums[start]
    }
    
    //3,4,5,6,7,0,1,2
    for start + 1 < end{
        mid := start + (end - start) /2 
        if (nums[mid] < nums[mid - 1] && 
        nums[mid] < nums[mid + 1]) {
            return nums[mid]
        }else if (nums[mid] > nums[0]){
            start = mid
        }else{
            end = mid
        }
    }
    
    if nums[start] < nums[end]{
        return nums[start]
    }
    return nums[end]
}

```

160. Find the minimum in rotated sorted array

O\(n\)

```cpp
 import("math")
 
func findMin (nums []int) int {
    // write your code here
    
    ret := math.MaxInt32
    
    for _, v := range nums{
        if v < ret{
            ret  = v
        }
    }
    return ret 
}
```

```cpp
/**
 * @param nums: a rotated sorted array
 * @return: the minimum number in the array
 */
func findMin (nums []int) int {
    // write your code here
    start := 0
    end := len(nums) -1 
    
    for start + 1 < end {
        
        mid := (start + end) /2 
        
        if nums[mid] == nums[end]{
            end--
        }else if nums[mid] < nums[end]{
            //middle is less than end, meaning 
            //the minimum must be on left side
            end = mid
        }else{
            start = mid
        }
    }
    
    if nums[start] < nums[end]{
        return nums[start]
    }
    return nums[end]
}

```



