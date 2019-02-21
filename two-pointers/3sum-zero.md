---
description: 'https://www.lintcode.com/problem/3sum/my-submissions'
---

# 3sum --zero

#### Description

Given an array _S_ of n integers, are there elements _a_, _b_, _c_ in _S_ such that `a + b + c = 0`? Find all unique triplets in the array which gives the sum of zero.

Elements in a triplet \(a,b,c\) must be in non-descending order. \(ie, a ≤ b ≤ c\)

The solution set must not contain duplicate triplets.Have you met this question in a real interview?  YesProblem Correction

#### Example

For example, given array S = `{-1 0 1 2 -1 -4}`, A solution set is:

```text
(-1, 0, 1)
(-1, -1, 2)
```

#### Related Problems



solution:

1 quick sort the array, this can't be avoided

2 start from the first element, and convert the problem to 

unique 2sum question.



```cpp
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        sort(numbers.begin(), numbers.end());
        vector<vector<int>> res;
        
        for(int i = 0 ;i < numbers.size(); i++){
            
            if ( i > 0 && numbers[i] == numbers[i-1]){
                continue;
            };
            
            int start = i + 1;
            int end = numbers.size() - 1;
            while( start < end){
                if (numbers[start] + numbers[end] == -numbers[i]){
                    vector<int> r = {numbers[i],numbers[start], numbers[end]};
                    res.push_back(r);
                    
                    start++;
                    end--;
                    while(start < end && numbers[start] == numbers[start-1]){
                        start++;
                    }
                    
                    while(start < end && numbers[end] == 
                    numbers[end+1]){
                        end--;
                    }
                }else if (numbers[start] + numbers[end] > -numbers[i]){
                    end--;
                }else{
                    start++;
                }
            }
        }
        return res;
    }
};
```

