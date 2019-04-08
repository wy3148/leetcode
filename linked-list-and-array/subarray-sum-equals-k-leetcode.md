# Subarray Sum Equals K \(leetcode\)



Given an array of integers and an integer **k**, you need to find the total number of continuous subarrays whose sum equals to **k**.

**Example 1:**  


```text
Input:nums = [1,1,1], k = 2
Output: 2
```

**Note:**  


1. The length of the array is in range \[1, 20,000\].
2. The range of numbers in the array is \[-1000, 1000\] and the range of the integer **k** is \[-1e7, 1e7\].

Note:

1 we firstly calculate the subarray sum from index 0 to index i ;

store these subarray sum into a hash map

2 then we iterate O\(n^2\) to get each subarray sum difference.

```go
func subarraySum(nums []int, k int) int {
    
    data := make(map[int]int)
    
    tmp := 0
    count := 0
    
    for i := 0; i < len(nums); i++{
        tmp += nums[i]
        data[i] = tmp
        if tmp == k {
            count++
        }
    }
    
    for i := 0; i< len(nums); i++{
        for j := i + 1; j < len(nums);j++{
            if data[j] - data[i] == k{
                count++
            }
        }
    }
    return count
}
```

There is O\(n\) solution,

using hashmap to record the all the calculated presum,

```cpp
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        // write your code here
        
        if (nums.size() == 0) return 0;
        
        map<int,int> sumData;
        int count = 0;
        int tmp = 0;
        
        //current sumarray sum val = k
        sumData[0]= 1; 
        
        for(int i = 0; i < nums.size(); i++){
            tmp += nums[i];
            count += sumData[tmp - k];
            
            sumData[tmp]++; // put current subarray
            //sum into the hashmap
        }
        return count;
    }
};
```



