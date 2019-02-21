---
description: 'https://www.lintcode.com/problem/merge-k-sorted-arrays/description'
---

# 486 Merge K Sorted Arrays



#### Description

Given _k_ sorted integer arrays, merge them into one sorted array.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given 3 sorted arrays:

```text
[
  [1, 3, 5, 7],
  [2, 4, 6],
  [0, 8, 9, 10, 11]
]
```

return `[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]`.

#### Challenge

Do it in O\(N log k\).

* _N_ is the total number of integers.
* _k_ is the number of arrays.

solution:

merge two sorted array by linear iterator of two arrays, then return this new array, and merge next array.

A better way is to implement a min heap

{% embed url="https://www.geeksforgeeks.org/merge-k-sorted-arrays/" %}



```cpp
class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekTwoSortedArrays(vector<int>& a, vector<int>& b){
        //time complexicity, n1 + n2; 
        int i = a.size() - 1;
        int j = b.size() - 1;
        int index = a.size() + b.size() - 1;
        vector<int> res(index + 1,0);
        
        while(i >= 0 && j >= 0){
            if (a[i] >= b[j]){
                res[index] = a[i];
                i--;
            }else{
                res[index] = b[j];
                j--;
            }
            index--;
        }
    
        while(i >= 0){
            res[index] = a[i];
            i--;
            index--;
        }
        
        while(j >= 0){
            res[index] = b[j];
            j--;
            index--;
        }
        return res;
    }
    
    // m * n 
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        vector<int> r = arrays[0];
        int j = 1;
        
        while(j < arrays.size()){
            r = mergekTwoSortedArrays(r,arrays[j]);
            j++;
        }
        return r;
    }
};
```

