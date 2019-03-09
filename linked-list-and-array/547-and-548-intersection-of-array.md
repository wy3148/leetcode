# 547&548 intersection of array

#### Description

中文English

Given two arrays, write a function to compute their intersection.

* Each element in the result must be unique.
* The result can be in any order.

Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2], 
Output: [2].
```

Example 2:

```text
Input: nums1 = [1, 2], nums2 = [2], 
Output: [2].
```

#### Challenge

Can you implement it in _three_ different algorithms?

```cpp
class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here
        
        vector<int> ret;
        set<int> data;
        
        for (auto v : nums1){
            data.insert(v);
        }
        
        for (auto v : nums2){
            if (data.find(v) != data.end()){
                ret.push_back(v);
                data.erase(v);
            }
        }
        return ret;
    }
};
```

548, if the element is duplicate in the array

```cpp
class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here
        
        vector<int> ret;
        
        map<int,int> data;
        for (auto v : nums1){
            data[v]++;
        }
        
        for (auto v : nums2){
            if (data[v] > 0) {
                ret.push_back(v);
                data[v]--;
            }
        }
        return ret;
    }
};
```

\`\`\`

#### Description

中文English

Given two arrays, write a function to compute their intersection.

* Each element in the result should appear as many times as it shows in both arrays.
* The result can be in any order.

Have you met this question in a real interview?  YesProblem Correction

#### Example

**Example1**

```text
Input: 
nums1 = [1, 2, 2, 1], nums2 = [2, 2]
Output: 
[2, 2]
```

**Example2**

```text
Input: 
nums1 = [1, 1, 2], nums2 = [1]
Output: 
[1]
```

#### Challenge

* What if the given array is already sorted? How would you optimize your algorithm?
* What if nums1's size is small compared to num2's size? Which algorithm is better?
* What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

