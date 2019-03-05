# 62 Search in rotated sorted array

#### Description

中文English

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

\(i.e., `0 1 2 4 5 6 7` might become `4 5 6 7 0 1 2`\).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input: [4, 5, 1, 2, 3] and target=1, 
Output: 2.
```

Example 2:

```text
Input: [4, 5, 1, 2, 3] and target=0, 
Output: -1.
```

#### Challenge

O\(logN\) time

Notes:

Still use binary search, but when middle element is the target number, we need to compare the 'start' index and 'mid' index to figure out it is rotated or not.

```cpp
/**
 * @param A: an integer rotated sorted array
 * @param target: an integer to be searched
 * @return: an integer
 */
func search (A []int, target int) int {
    // write your code here
    //4 5 6 7 0 1 2
    if len(A) == 0 {
        return -1
    }
    start := 0
    end := len(A) -1 
    
    //[1,2,3,4,5,9]
    //9
    //[100,10001,10002,1,2,99,100] 10001
    
    for start + 1 < end{
        mid := (start + end)/2 
        if A[mid] == target{
            return mid
        }
        
        //middle position is in rotated side or not
        //then check the range the target will be within
        //NOT WITH A[0] compare
        if (A[start] < A[mid]) {
            // situation 1, red line
            if (A[start] <= target && target <= A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        } else {
            // situation 2, green line
            if (A[mid] <= target && target <= A[end]) {
                start = mid;
            } else {
                end = mid;
            }
        }
    }
    if (A[start] == target){
        return start
    }else if (A[end] == target){
        return end
    }
    return -1
}

```



Follow up



Follow up for [Search in Rotated Sorted Array](http://www.lintcode.com/problem/search-in-rotated-sorted-array/):

What if **duplicates** are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input:
[]
1
Output:
false
```

Example 2:

```text
Input:
[3,4,4,5,7,0,1,2]
4
Output:
true
```

This is hard to be resolved by binary search, since there are too many duplicate/edge cases.

