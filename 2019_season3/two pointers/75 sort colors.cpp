// 75. Sort Colors
// DescriptionHintsSubmissionsDiscussSolution
// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note: You are not suppose to use the library's sort function for this problem.

// Example:

// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Follow up:

// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// Could you come up with a one-pass algorithm using only constant space?

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //[2,0,2,1,1,0]
        //[0,0,1,1,2,2]
        //count sort is not allowed to implement this algorithm
        if (nums.size() == 0) return;
        int left = 0;
        int right = nums.size() - 1;
        int m = 0; //middle
        
        //算法的核心思路是 确认和移动middle的位置；middle位置1；如果middle
        //当前为1，middle可以递增直到不是1, 如果middle是0, middle为left
        //middle递增，middle 为2 ,middle左移
        
        while( m <= right){
            
            //类似数组的reuse, m 指向从最左侧开始
            
            if (nums[m] == 1){
                m++;
            }else if (nums[m] == 0){
                //把m处的0和最左left的值swap，那么left一定成为了0;
                swap(nums[m],nums[left]);
                left++;
                m++;
            }else if(nums[m] == 2){
                swap(nums[m],nums[right]); //2 和最right的位置交换，那么right一定是2了
                right--;
            }
        }
    }
};
