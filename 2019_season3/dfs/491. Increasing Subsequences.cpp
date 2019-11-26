// 491. Increasing Subsequences
// DescriptionHintsSubmissionsDiscussSolution
// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.

 

// Example:

// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 

// Note:

// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence


class Solution {
public:
    
    set <vector<int>> data;
    void dfs(vector<int>& nums ,vector<int> tmp, int pos){
        if( tmp.size() >= 2){
            data.insert(tmp);
        }
        for(int i = pos; i < nums.size(); i++){
            if (tmp.size() == 0 || nums[i] >= tmp[tmp.size() - 1]){
                tmp.push_back(nums[i]);
                dfs(nums,tmp, i + 1);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>  ret;
        
        for(int i = 0; i < nums.size(); i++){
            vector<int> tmp;
            dfs(nums,tmp,i);
        }
        
        for(auto& v : data){
            ret.push_back(v);
        }
        return ret;
    }
};
