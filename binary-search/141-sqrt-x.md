# 141 sqrt\(x\)

#### Description

Implement int `sqrt(int x)`.

Compute and return the square root of _x_.Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
Example 1:
	Input:  0
	Output: 0


Example 2:
	Input:  3
	Output: 1
	
	Explanation:
	return the largest integer y that y*y <= x. 
	
Example 3:
	Input:  4
	Output: 2
	

```

#### Challenge

O\(log\(x\)\)

#### Related Problems

```cpp
/**
 * @param x: An integer
 * @return: The sqrt of x
 */
func sqrt (x int) int {
    // write your code here
    
    if x <= 1 {
        return x
    }
    
    start := 0
    end := x/2
    
    for start + 1 < end{
        mid := (start + end) /2 
        if mid * mid  == x {
            return mid
        }else if (mid *  mid > x){
            end = mid
        }else{
            start = mid
        }
    }
    
    if end * end <= x {
        return end
    }
    return start
}

```

