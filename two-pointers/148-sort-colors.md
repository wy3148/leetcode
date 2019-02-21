# 148 sort colors



#### Description

Given an array with _n_ objects colored _red_, _white_ or _blue_, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers `0`, `1`, and `2` to represent the color red, white, and blue respectively.

You are not suppose to use the library's sort function for this problem.  
You should do it in-place \(sort numbers in the original array\).Have you met this question in a real interview?  YesProblem Correction

#### Example

Given `[1, 0, 1, 2]`, sort it in-place to `[0, 1, 1, 2]`.

#### Challenge

A rather straight forward solution is a two-pass algorithm using counting sort.  
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

#### Related Problems

[625. Partition Array II](https://www.lintcode.com/problem/partition-array-ii)[508. Wiggle Sort](https://www.lintcode.com/problem/wiggle-sort)[507. Wiggle Sort II](https://www.lintcode.com/problem/wiggle-sort-ii)[143. Sort Colors II](https://www.lintcode.com/problem/sort-colors-ii)[39. Recover Rotated Sorted Array](https://www.lintcode.com/problem/recover-rotated-sorted-array)

* 


```cpp
class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        
        // 1,0,1,2
        int left = 0, right = nums.size() - 1;
        int middle = 0;
        
        // should be <= not <
        while (middle <= right) {
            if (nums[middle] == 0) {
                swap(nums[middle], nums[left]);
                left++;
                middle++;
            } else if (nums[middle] == 1) {
                middle++;
            } else {
                swap(nums[middle], nums[right]);
                right--;
            }
        }
    }
};
```

original answer is counting the number of 0,1,2.



