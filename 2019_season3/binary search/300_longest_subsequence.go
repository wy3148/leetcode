// 300. Longest Increasing Subsequence
// DescriptionHintsSubmissionsDiscussSolution
// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Note:

// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?

func lengthOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	maxLen := 1

	//dp formula
	//i position
	//if nums[i] > nums[j], f[i] = f[j] + 1 ( j >= 0 && j < i)
	ret := make([]int, len(nums))
	for i, _ := range ret {
		ret[i] = 1
	}

	//[10,9,2,5,3,7,101,18]
	//[2,3,7,101]

	for i := 0; i < len(nums); i++ {

		//初始长度为1， 就是元素本身的长度
		tmp := 1

		//查找i之前的元素 只要比i小，就可以在原有基础上长度+1；
		//然后选其中最大的值
		for j := i - 1; j >= 0; j-- {
			if nums[i] > nums[j] {
				if tmp < ret[j]+1 {
					tmp = ret[j] + 1
				}
			}
			ret[i] = tmp
			if maxLen < tmp {
				maxLen = tmp
			}
		}
	}
	return maxLen
}
