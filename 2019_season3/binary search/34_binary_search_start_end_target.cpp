// 34. Find First and Last Position of Element in Sorted Array
// DescriptionHintsSubmissionsDiscussSolution
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

func searchRange(nums []int, target int) []int {
    
    ret := []int{-1,-1}
    
    if len(nums) == 0 {
        return ret
    }
    
    left := 0
    right := len(nums) - 1
    
    //[5,7,7,8,8,10] 
    //8
    
    for left + 1 < right{
        mid := (left + right) / 2
        if (nums[mid] >= target){
            right = mid
        }else{
            left = mid
        }
    }
    
    //binary search to find the position of the element
    //which the value is less than the target value
    for left < len(nums){
        if (nums[left] < target){
            left++
            continue
        }else if (nums[left] == target){
            if (ret[0] == -1){
                ret[0]= left
            }else{
                ret[1] = left
            }
            left++
        }else{
            break
        }
    }
    
    if ret[1] == -1{
        ret[1] = ret[0]
    }
    
    return ret
}
