// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int pos = 0;
        
        for(int i = 0; i < nums.size(); i++ ){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }else{
                nums[pos] = nums[i];
                pos++;
            }
        }
        return pos;
    }
};
