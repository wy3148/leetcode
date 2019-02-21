# string permuation



#### Description

Given two strings, write a method to decide if one is a permutation of the other.Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
Example 1:
	Input:  "abcd", "bcad"
	Output:  True


Example 2:
	Input: "aac", "abc"
	Output:  False
```

Notes:

**using dfs to calculate all possible permutations takes too much time, we don't need dfs in this case in fact.**

```cpp
/**
 * @param A: a string
 * @param B: a string
 * @return: a boolean
 */
 
var res []string

func dfs(A string,B string, tmp []byte, visited map[int]bool,
result *bool){
    
    if (len(tmp) == len(A)){
        if string(tmp) == B{
            *result = true
            return
        }
    }
    
    for i := 0; i < len(A); i++{
        if (visited[i] == false){
            visited[i] = true
            tmp = append(tmp,A[i])
            dfs(A,B,tmp,visited,result)
            visited[i] = false
            tmp = tmp[:len(tmp) - 1]
        }
    }
}

func Permutation (A string, B string) bool {
    // write your code here
    
    visited := make(map[int]bool)
    var tmp []byte
    result := false
    dfs(A, B,tmp, visited,&result)
    return result
}

```

```cpp
/**
 * @param A: a string
 * @param B: a string
 * @return: a boolean
 */
func Permutation (A string, B string) bool {
    // write your code here
    
    if len(A) != len(B){
        return false
    }
    
    m1 := make(map[byte]int) 
    m2 := make(map[byte]int)
    
    for i := 0; i < len(A); i++{
        m1[A[i]]++
        m2[B[i]]++
    }
    
    for k, v := range m1{
        if m2[k] != v{
            return false
        }
    }
    return true
}

```

we can simply use the hashmap to compare the number of character in string.

