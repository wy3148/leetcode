---
description: 'https://www.lintcode.com/problem/sort-colors-ii/description'
---

# 143 sort colors II

#### Description

Given an array of _n_ objects with _k_ different colors \(numbered from 1 to k\), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

1. You are not suppose to use the library's sort function for this problem.
2. `k` &lt;= `n`

Have you met this question in a real interview?  YesProblem Correction

#### Example

Given colors=`[3, 2, 2, 1, 4]`, `k=4`, your code should sort colors in-place to `[1, 2, 2, 3, 4]`.

#### Challenge

A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O\(k\) extra memory. Can you do it without using extra memory?



```cpp
class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        partition(colors,0,colors.size() - 1, 1, k);
    }
    
    void partition(vector<int> &colors,int start,int end, 
    int startk, int endk){
        
        if(start >= end || startk >= endk) return;
        
        int i = start;
        int j = end;
        
        //[3, 2, 2, 1, 4], k=4
        int midk = (endk + startk) / 2;
        
        while (i <= j) {
            while (i <= j && colors[i] <= midk) {
                i++;
            }
            while (i <= j && colors[j] > midk) {
                j--;
            }
            if (i <= j) {
                int temp = colors[j];
                colors[j] = colors[i];
                colors[i] = temp;
                i++;
                j--;
            }
        }
        
        partition(colors, start, j, startk, midk);
        partition(colors, i, end, midk+1, endk);
    }
};
```



