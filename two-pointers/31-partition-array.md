---
description: 'https://www.lintcode.com/problem/partition-array/description'
---

# 31 partition array



#### Description

Given an array `nums` of integers and an int `k`, partition the array \(i.e move the elements in "nums"\) such that:

* All elements &lt; _k_ are moved to the _left_
* All elements &gt;= _k_ are moved to the _right_

Return the partitioning index, i.e the first index _i_ nums\[_i_\] &gt;= _k_.

You should do really partition in array _nums_ instead of just counting the numbers of integers smaller than k.

If all elements in _nums_ are smaller than _k_, then return _nums.length_Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input:
[],9
Output:
0

```

Example 2:

```text
Input:
[3,2,2,1],2
Output:1
Explanation:
the real array is[1,2,2,3].So return 1
```

#### Challenge

Can you partition the array in-place and in O\(n\)?

#### Related Problems

[769. Spiral Array](https://www.lintcode.com/problem/spiral-array)[761. Smallest Subset](https://www.lintcode.com/problem/smallest-subset)[625. Partition Array II](https://www.lintcode.com/problem/partition-array-ii)[373. Partition Array by Odd and Even](https://www.lintcode.com/problem/partition-array-by-odd-and-even)[144. Interleaving Positive and Negative Numbers](https://www.lintcode.com/problem/interleaving-positive-and-negative-numbers)[96. Partition List](https://www.lintcode.com/problem/partition-list)

Note: the if condition is i &lt;= j,  it is required to return first index of element which is &gt;=k.

```cpp
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        if (nums.size() == 0) return 0;
        int i = 0;
        int j = nums.size() - 1;
        
        while(i <= j){
            while(i <= j && nums[i] < k) i++;
            while(i <= j && nums[j] >= k) j--;
            
            while(i <= j ){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }
        return i;
    }
};
```

