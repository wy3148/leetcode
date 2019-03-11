# 521 remove duplicate in array

**Description**  
Given an array of integers, remove the duplicate numbers in it.  
  
You should:  
1. Do it in place in the array.  
2. Move the unique numbers to the front of the array.  
3. Return the total number of the unique numbers.  
  
  
**Notice**  
You don't need to keep the original order of the integers.  
  
  
  
**Example**  
Given nums = \[1,3,1,4,4,2\], you should:  
  
Move duplicate integers to the tail of nums =&gt; nums = \[1,3,4,2,?,?\].  
Return the number of unique integers in nums =&gt; 4.  
Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.  
  
  
**Challenge**  
Do it in O\(n\) time complexity.  
Do it in O\(nlogn\) time without extra space.

```go
package main

import (
	"fmt"
)

func removeDuplicate(nums []int) []int {
	if nums == nil {
		return nums
	}

	data := make(map[int]struct{})
	var ret []int
	for _, v := range nums {
		if _, ok := data[v]; !ok {
			ret = append(ret, v)
			data[v] = struct{}{}
		}
	}
	return ret
}

func main() {
	fmt.Println(removeDuplicate(nil))
	fmt.Println(removeDuplicate([]int{1, 2, 3, 4}))
	fmt.Println(removeDuplicate([]int{1, 1, 1, 2, 3, 4}))
	fmt.Println(removeDuplicate([]int{5, 4, 3, 3, 3, 3, 3, 3, 1}))
	fmt.Println(removeDuplicate([]int{1, 1, 1, 1, 1, 1}))
}
```

```go
func removeDuplicateV2(nums []int) []int {
	if nums == nil {
		return nums
	}

	sort.Ints(nums)

	//1,2,2,3,4,5
	index := 0
	i := 1
	for index < len(nums) && i < len(nums) {
		if nums[i] != nums[index] {
			index++
			nums[index] = nums[i]
			i++
		} else {
			i++
		}
	}
	return nums[:index+1]
}
```

