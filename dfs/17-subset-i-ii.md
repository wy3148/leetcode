---
description: 'https://www.lintcode.com/problem/subsets/description'
---

# 17 subset I II



#### Description

中文English

Given a set of distinct integers, return all possible subsets.

* Elements in a subset must be in _non-descending_ order.
* The solution set must not contain duplicate subsets.

Have you met this question in a real interview?  YesProblem Correction

#### Example

**Example 1:**

```text
Input: [0]
Output:
[
  [],
  [0]
]
```

**Example 2:**

```text
Input: [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
```

#### Challenge

Can you do it in both recursively and iteratively?

#### Related Problems

[1210. Increasing Subsequences](https://www.lintcode.com/problem/increasing-subsequences)[935. Cartesian Product](https://www.lintcode.com/problem/cartesian-product)[761. Smallest Subset](https://www.lintcode.com/problem/smallest-subset)[730. Sum of All Subsets](https://www.lintcode.com/problem/sum-of-all-subsets)[680. Split String](https://www.lintcode.com/problem/split-string)[426. Restore IP Addresses](https://www.lintcode.com/problem/restore-ip-addresses)[18. Subsets II](https://www.lintcode.com/problem/subsets-ii)

```cpp
class Solution {
public:


    void dfs(vector<vector<int>>& res, vector<int>& nums,vector<int>& subset, 
    int pos){
        
        res.push_back(subset);
        
        for(int i = pos;i < nums.size(); i++){
            subset.push_back(nums[i]);
            dfs(res,nums,subset,i+1);
            subset.pop_back();
        }
    }
    
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(res,nums,subset,0);
        return res;
    }
};
```

#### Example

**Example 1:**

```text
Input: [1,1]
Output:
[
  [1,1]
]
```

**Example 2:**

```text
Input: [1,2,2]
Output:
[
  [1,2,2],
  [2,1,2],
  [2,2,1]
]
```

#### Challenge

Using recursion to do it is acceptable. If you can do it without recursion, that would be great!

#### Related Problems

Notes:

to remove the duplicate result, we can use data structure 'set'. but it's the not the best answer.

```cpp
class Solution {
public:

    std::set<vector<int>> myset;
    
    void dfs(vector<vector<int>>& res,vector<int>& nums,
    vector<int>& tmp,vector<bool>& visited){
        if (tmp.size() == nums.size() && 
        myset.find(tmp) == myset.end()){
            res.push_back(tmp);
            myset.insert(tmp);
        }
        
        //[1,2,2]
        for(int i = 0; i < nums.size(); i++){
            if (visited[i] == false){
                visited[i] = true;
                tmp.push_back(nums[i]);
                dfs(res,nums,tmp,visited);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }

    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        
        dfs(res,nums,tmp,visited);
        return res;
    }
};
```

```cpp
class Solution {
public:

    void dfs(vector<vector<int>>& res,vector<int>& nums,
    vector<int>& tmp,vector<bool>& visited,int pos){
        if (tmp.size() == nums.size()){
            res.push_back(tmp);
        }
        
        //[1,2,2]
        for(int i = 0; i < nums.size(); i++){
            
            
            //current number appears, and the previous index
            //not visited yet.
            
            //if the previous is visitied, we can still add the number
            
            //1, 2, 2  [1,2] ==next is index=2, number is 2; we can still add
            if (i > 0 && nums[i] == nums[i - 1] 
            && visited[i - 1] == false) { 
                continue; 
            }
            
            if (visited[i] == false){
                visited[i] = true;
                tmp.push_back(nums[i]);
                dfs(res,nums,tmp,visited,i);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }

    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        
        dfs(res,nums,tmp,visited,0);
        return res;
    }
};
```

