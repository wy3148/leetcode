# 74 First Bad Version

#### Description

中文English

The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call `isBadVersion` to help you determine which version is the first bad one. The details interface can be found in the code's annotation part.

Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is `SVNRepo.isBadVersion(v)`Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
Given n = 5:

    isBadVersion(3) -> false
    isBadVersion(5) -> true
    isBadVersion(4) -> true

Here we are 100% sure that the 4th version is the first bad version.
```

#### Challenge

You should call _isBadVersion_ as few as possible.

#### Related Problems

Notes:

Binary search

```cpp
/**
 * @param n: An integer
 * @return: An integer which is the first bad version.
 */
func findFirstBadVersion (n int) int {
    // write your code here
    
    start := 1
    end := n
    
    for start + 1 < end{
        mid := (start + end) / 2 
        if isBadVersion(mid){
            end = mid
        }else{
            start = mid
        }
    }
    if isBadVersion(start){
        return start
    }
    return end
}

```

