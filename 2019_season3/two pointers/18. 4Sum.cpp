
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:

// The solution set must not contain duplicate quadruplets.

// Example:

// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if (nums.size() < 4) return ret;
        
        for(int i = 0; i < nums.size() - 3; i++){
            
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            
            for(int j = i +1; j < nums.size() -2; j++){
                
                if (j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                
                int l = j + 1;
                int r = nums.size() -1;
                
                while( l < r){
                    
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    
                    if (sum == target){
                        ret.push_back({nums[i],nums[j],nums[l],nums[r]});
                        
                        
                        //two pointers之后 也是需要去重 这里是比较容易忽略的地方
                        l++;
                        while(l < r && nums[l] == nums[l- 1]){
                            l++;
                        }
                        
                        r--;
                        while(l < r && nums[r] == nums[r + 1]){
                            r--;
                        }
                    }else if(sum > target){
                        r--;
                    }else{
                        l++;
                    }   
                }
            }
        }
        return ret;
    }
};

//Golang version

import "sort"

func fourSum(nums []int, target int) [][]int {
    
    sort.Ints(nums)
    
    var ret [][]int
    
    if len(nums) < 4 {
        return ret
    }
    
    for i:= 0; i < len(nums) - 3; i++ {
        
        if ( i > 0 && nums[i] == nums[i -1]){
            continue
        }
        
        for j := i + 1; j < len(nums) -2; j++{
            
            if (j > i +1  && nums[j] == nums[j - 1]){
                continue
            }
            
            l := j + 1
            r := len(nums) - 1

            for l < r {
                
                sum := nums[i] + nums[j] + nums[l] + nums[r]
                
                if sum == target{
                    ret = append(ret,[]int{nums[i],nums[j],nums[l],nums[r]})
                    
                    l++
                    for l < r && nums[l] == nums[l - 1]{
                        l--
                    }
                    
                    r--
                    for l < r && nums[r] == nums[r + 1]{
                        r--
                    }
                }else if sum > target{
                    r--
                }else{
                    l++
                }

            }
        }
    }
    return ret
}
