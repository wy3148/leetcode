
// 80. Remove Duplicates from Sorted Array II
// DescriptionHintsSubmissionsDiscussSolution
// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,1,2,3,3],

// Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

// It doesn't matter what values are set beyond the returned length.
// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

// Internally you can think of this:

// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);

// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }


//类似reuse array，需要一个额外的变量left,记录新的数组的起始位置
class Solution {
public:
    
    //[0,0,1,1,1],
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int left = 1;
        int repeat = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[left] = nums[i];
                left++;
                repeat = 0;            
            }else{
                if (repeat < 1){
                    nums[left] = nums[i];
                    left++;
                    repeat++;
                }
            }
        }
        return left;
    }
};




//Golang
func removeDuplicates(nums []int) int {
    
    if len(nums) == 0 {
        return 0
    }
    
    left := 1
    repeat := 0
    
    for i := 1; i < len(nums); i++{
        if (nums[i] != nums[i - 1]){
            repeat = 0;
            nums[left] = nums[i]
            left++
        }else if (repeat < 1){
            nums[left] = nums[i]
            left++;
            repeat++
        }
    }
    return left
}