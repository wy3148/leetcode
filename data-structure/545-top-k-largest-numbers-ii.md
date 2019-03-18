---
description: 'https://www.lintcode.com/problem/top-k-largest-numbers-ii/description'
---

# 545&606 Top k Largest Numbers II



#### Description

Implement a data structure, provide two interfaces:

1. `add(number)`. Add a new number in the data structure.
2. `topk()`. Return the top _k_ largest numbers in this data structure. _k_ is given when we create the data structure.

Have you met this question in a real interview?  YesProblem Correction

#### Example

```text
s = new Solution(3);
>> create a new data structure.
s.add(3)
s.add(10)
s.topk()
>> return [10, 3]
s.add(1000)
s.add(-99)
s.topk()
>> return [1000, 10, 3]
s.add(4)
s.topk()
>> return [1000, 10, 4]
s.add(100)
s.topk()
>> return [1000, 100, 10]

```

```cpp
class Solution {

private:
    int tk;
    vector<int> data;
public:
    /*
    * @param k: An integer
    */Solution(int k) {
        // do intialization if necessary
        tk = k;
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        data.push_back(num);
    }
    
    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        sort(data.begin(),data.end());
        reverse(data.begin(),data.end());
        if (data.size() < tk) return data;
        vector<int> r(data.begin(),data.begin() + tk);
        return r;
    }
};
```

use 'priority\_queue' max-heap to store and update K largest numbers, when call Topk\(\) function, pop these elements and then pop back

```cpp

class Solution {

public:

    class Compare{
    public:
         bool operator()(int& a, int& b){
              return a > b;
         }
    };

    int numK;    
    priority_queue<int,vector<int>, Compare> q;

    /*
    * @param k: An integer
    */Solution(int k) {
        // do intialization if necessary
        numK =k;
    }
    
    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        q.push(num);
        while(q.size() > numK){
            q.pop();
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        vector<int> ret;
        
        //we can clone the existing queue, and pop up
        //or we can pop from the existing queue, and pop
        //them back
        priority_queue<int,vector<int>, Compare> cloneQ(q);
        while(cloneQ.size() > 0){
            ret.insert(ret.begin(),cloneQ.top()); cloneQ.pop();
        }
        return ret;
    }
};
```



**Description**  
Find K-th largest element in an array. and N is much larger than k.  
  
  
**Notice**  
You can swap elements in the array  
  
  
  
**Example**  
In array \[9,3,2,4,8\], the 3rd largest element is 4.  
  
In array \[1,2,3,4,5\], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.  


'priority\_queue' or 'quick select'



