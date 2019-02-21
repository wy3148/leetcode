---
description: 'https://www.lintcode.com/problem/3sum-closest/description'
---

# 59 3Sum Closest

#### Description

Given an array S of _n_ integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

You may assume that each input would have exactly one solution.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input:[2,7,11,15],3
Output:20
Explanation:
2+7+11=20
```

Example 2:

```text
Input:[-1,2,1,-4],1
Output:2
Explanation:
-1+2+1=2
```

#### Challenge

O\(n^2\) time, O\(1\) extra space



```cpp
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        if (numbers.size() == 0) return 0;
        
        sort(numbers.begin(),numbers.end());
        int diff = INT_MAX;
        int res = 0;
        
        for(int i = 0; i < numbers.size(); i++){
            
            if (i > 0 && numbers[i] == numbers[i - 1]) continue;
            
            int start = i + 1;
            int end = numbers.size() -1; 
            
            while(start < end){
                if (numbers[start] + numbers[end] + numbers[i] == target){
                    return target;
                }else if(numbers[start] + numbers[end] + numbers[i] > target ){
                    if (abs(numbers[start] + numbers[end] + numbers[i] - target) < diff){
                        res = numbers[start] + numbers[end] + numbers[i];
                        diff = abs(numbers[start] + numbers[end] + numbers[i] - target);
                    }
                    end--;
                }else{
                    if (abs(numbers[start] + numbers[end] + numbers[i] - target) < diff){
                        res = numbers[start] + numbers[end] + numbers[i];
                        diff = abs(numbers[start] + numbers[end] + numbers[i] - target);
                    }
                    start++;
                }
            }
        }
        return res;
    }
};
```

