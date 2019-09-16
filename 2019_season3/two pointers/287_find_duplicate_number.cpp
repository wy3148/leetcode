// 287. Find the Duplicate Number
// DescriptionHintsSubmissionsDiscussSolution
// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

// Example 1:

// Input: [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: [3,1,3,4,2]
// Output: 3
// Note:

// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.

import "math"

func findDuplicate(nums []int) int {
    
    m := len(nums)
    
    if m == 0{
        return math.MaxInt32
    }
    
    
    //l, r 并不是数组下标！！！而是1 ~ n 的取值
    l := 1
    r := m - 1;
    
    //[1,3,4,2,2]
    // l = 0 , r = 4
    for l < r {
        mid := (l + r ) / 2
        count := 0
        
        //每次遍历的时候始终遍历整个数组的所有元素；只是统计元素和中值大小关系的比较
        for _, v := range nums{
            if v <= mid{
                count++
            }
        }
        
        if count <= mid{
            l = mid + 1   
        }else{
            r = mid
        }
    }
    return r  
}
