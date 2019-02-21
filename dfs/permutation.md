# permutation



#### Description

中文English

Given a list of numbers, return all possible permutations.

You can assume that there is no duplicate numbers in the list.Have you met this question in a real interview?  YesProblem Correction

#### Example

**Example 1:**

```text
Input: [1]
Output:
[
  [1]
]
```

**Example 2:**

```text
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

#### Challenge

Do it without recursion.

#### Related Problems

[935. Cartesian Product](https://www.lintcode.com/problem/cartesian-product)[371. Print Numbers by Recursion](https://www.lintcode.com/problem/print-numbers-by-recursion)[388. Permutation Sequence](https://www.lintcode.com/problem/permutation-sequence)[16. Permutations II](https://www.lintcode.com/problem/permutations-ii)

Notes:

because it is a permutations, each result will include all element,

so in function, each time we need to iterator element from the beginning index, but we need a flag to indicate if we visited the element or no. 

```cpp
class Solution {
public:

    void dfs(vector<vector<int>>& res,vector<int> &nums,vector<int>& tmp,
    vector<bool>& visited){
        
        if (tmp.size() == nums.size()){
            res.push_back(tmp);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if (visited[i] == false){
                tmp.push_back(nums[i]);
                visited[i] = true;
                dfs(res,nums,tmp,visited);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }

    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);
        
        dfs(res,nums,tmp,visited);
        return res;
    }
};
```

