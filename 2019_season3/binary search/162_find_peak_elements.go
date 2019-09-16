// 162. Find Peak Element
// DescriptionHintsSubmissionsDiscussSolution
// A peak element is an element that is greater than its neighbors.

// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that nums[-1] = nums[n] = -∞.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1 where the peak element is 2,
//              or index number 5 where the peak element is 6.
// Note:

// Your solution should be in logarithmic complexity.

func findPeakElement(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}
	l := 0
	r := len(nums) - 1

	//[1,2,2,3,2]
	for l+1 < r {
		mid := (l + r) / 2
		if nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] {
			return mid
		} else if nums[mid] < nums[mid-1] {
			r = mid
		} else {
			l = mid
		}
	}

	if nums[l] > nums[r] {
		return l
	}
	return r
}