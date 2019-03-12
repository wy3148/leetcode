# 610 Two Sum - Difference equals to target

**Description**  
Given an array of integers, find two numbers that their difference equals to a target value.  
where index1 must be less than index2. Please note that your returned answers \(both index1 and index2\) are NOT zero-based.  
  
  
**Notice**  
It's guaranteed there is only one available solution  
  
  
  
**Example**  
Given nums = \[2, 7, 15, 24\], target = 5  
return \[1, 2\] \(7 - 2 = 5\)  


Notes:

sort or hashmap

```text
public int[] twoSum7(int[] nums, int target) {
    HashMap<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int sum = nums[i] + target;
        if (map.containsKey(sum)) {
            int index = map.get(sum);
            int[] pair = new int[2];
            pair[0] = index + 1;
            pair[1] = i + 1;
            return pair;
        }
        
        int diff = nums[i] - target;
        if (map.containsKey(diff)) {
            int index = map.get(diff);
            int[] pair = new int[2];
            pair[0] = index + 1;
            pair[1] = i + 1;
            return pair;
        }
        map.put(nums[i], i);
    }
    
    return null;
}
```

