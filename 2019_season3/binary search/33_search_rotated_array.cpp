// 33. Search in Rotated Sorted Array
// DescriptionHintsSubmissionsDiscussSolution
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int ret = -1;
        if (nums.empty()) return ret;
        
        int left = 0;
        int right = nums.size() -1;
        
        
        //left +1 < right, cover [1] case
        while(left  + 1 < right){
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) return mid;
            
            if (nums[mid] > nums[left]){
                
                //比较target的值，确认应该在哪个区间range
                if (target >= nums[left] && target < nums[mid]){
                    right = mid;
                }else{
                    left = mid;
                }
            }else{
                if (target > nums[mid] && target <= nums[right]){
                    left = mid;
                }else{
                    right = mid;
                }
            }
        }
        
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return ret;
    }
};
