---
description: 'https://www.lintcode.com/problem/two-sum-iii-data-structure-design/description'
---

# 607. Two Sum III - Data structure design



#### Description

Design and implement a TwoSum class. It should support the following operations: `add` and `find`.

`add` - Add the number to an internal data structure.  
`find` - Find if there exists any pair of numbers which sum is equal to the value.Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
add(1); add(3); add(5);
find(4) // return true
find(7) // return false
```

#### Related Problems

[608. Two Sum II - Input array is sorted](https://www.lintcode.com/problem/two-sum-ii-input-array-is-sorted)[648. Unique Word Abbreviation](https://www.lintcode.com/problem/unique-word-abbreviation)[610. Two Sum - Difference equals to target](https://www.lintcode.com/problem/two-sum-difference-equals-to-target)[609. Two Sum - Less than or equal to target](https://www.lintcode.com/problem/two-sum-less-than-or-equal-to-target)[587. Two Sum - Unique pairs](https://www.lintcode.com/problem/two-sum-unique-pairs)[533. Two Sum - Closest to target](https://www.lintcode.com/problem/two-sum-closest-to-target)[443. Two Sum - Greater than target](https://www.lintcode.com/problem/two-sum-greater-than-target)[56. Two Sum](https://www.lintcode.com/problem/two-sum)



works , but the algorithm is not the best solution, 'exceed the time limit'.

solution:

using the array won't help solve the performance issue. 

should use hashmap instead.



```cpp
class TwoSum {


private:
    unordered_set<int> data;
    std::vector<int> nums;
public:

    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        
        for(auto v : nums){
            data.insert(number + v);
        }
        
        nums.push_back(number);
    }
    
    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        return data.find(value) != data.end();
    }
};
```

the better solution

```cpp
class TwoSum {
public:
    unordered_map<int,int> m;
    
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        m[number]++;
    }
    
    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        for (auto v : m){
            int key = value - v.first;
            if (key != v.first){
                if (m.find(key) != m.end()) return true;
            }else{
                if (m[key] > 1 ) return true;   
            }
        }
        return false;
    }
};
```





