# 61 Search for a Range

#### Description

中文English

Given a sorted array of _n_ integers, find the starting and ending position of a given target value.

If the target is not found in the array, return `[-1, -1]`.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input:
[]
9
Output:
[-1,-1]

```

Example 2:

```text
Input:
[5, 7, 7, 8, 8, 10]
8
Output:
[3, 4]
```

#### Challenge

O\(log _n_\) time.

Notes:

we need to find the start position which is less than the target value.

then iterate from the start index.

```cpp
/**
 * @param A: an integer sorted array
 * @param target: an integer to be inserted
 * @return: a list of length 2, [index1, index2]
 */
func searchRange (A []int, target int) []int {
    // write your code here
    var res []int 
    res = append(res,-1,-1)
    
    if len(A) == 0{
        return res
    }
    
    start := 0
    end := len(A) - 1 
    
    for start + 1 < end {
        mid := (start + end) /2 
        if (A[mid] >= target){
            end = mid
        }else{
            start = mid
        }
    }
    
    for start < len(A){
        if A[start] == target{
            if res[0] == -1{
                res[0] = start
            }else{
                res[1] = start
            }
        }else if A[start] > target{
            break
        }
        start++
    }
    if res[1] == -1 {
        res[1] = res[0]
    }
    return res
}

```

