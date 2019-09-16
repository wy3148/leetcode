
// 930. Binary Subarrays With Sum
// DescriptionHintsSubmissionsDiscussSolution
// In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

// Example 1:

// Input: A = [1,0,1,0,1], S = 2
// Output: 4
// Explanation: 
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
 

// Note:

// A.length <= 30000
// 0 <= S <= A.length
// A[i] is either 0 or 1.

func numSubarraysWithSum(A []int, S int) int {
    //[1,0,1,0,1]
    //prefix sum
    //1, 1, 2, 2, 3
    // S = 2
    
    var prefix []int
    sum := 0
    ret := 0
    
    for _, v := range A {
        sum += v
        prefix = append(prefix,sum)    
        if sum == S{
            ret++
        }   
    }
    
    for i := 0; i < len(prefix); i++{
        for j := i + 1; j < len(prefix); j++{
            if prefix[j] - prefix[i] == S{
                ret++
            }
        }
    }
    return ret
}
