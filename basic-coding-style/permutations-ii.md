---
description: 'https://www.lintcode.com/problem/permutations-ii/description'
---

# Permutations II

#### Description

Given a list of numbers with duplicate number in it. Find all **unique** permutations.Have you met this question in a real interview?  YesProblem Correction

#### Example

For numbers `[1,2,2]` the unique permutations are:

```text
[
  [1,2,2],
  [2,1,2],
  [2,2,1]
]
```

#### Challenge

Using recursion to do it is acceptable. If you can do it without recursion, that would be great!  


```cpp
class Solution {
public:

    void helper(vector<vector<int>>& res, vector<int>& nums, 
    vector<int>& r,vector<bool>& visited){
        
        if (r.size() == nums.size()){
            res.push_back(r);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if (visited[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && visited[i - 1] == false) continue;
            
            r.push_back(nums[i]);
            visited[i] = true;
            helper(res,nums,r,visited);
            visited[i] = false;
            r.pop_back();
        }
    }

    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> r;
        vector<bool> visited(nums.size(), false);
        helper(res,nums,r,visited);
        return res;
    }
};
```

