# ugly number-II

[https://www.lintcode.com/problem/ugly-number-ii/description](https://www.lintcode.com/problem/ugly-number-ii/description)

[https://www.lintcode.com/problem/ugly-number/description](https://www.lintcode.com/problem/ugly-number/description)





#### Description

中文English

Write a program to check whether a given number is an `ugly` number\`.

`Ugly numbers` are positive numbers whose prime factors only include `2`, `3`, `5`. For example, `6`, `8` are ugly while `14` is not ugly since it includes another prime factor `7`.

Note that `1` is typically treated as an ugly number.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input: num = 8 
Output: true
Explanation:
8=2*2*2
```

Example 2:

```text
Input: num = 14 
Output: false
Explanation:
14=2*7 
```

#### Related Problems

if a number is ugly number, it must be always multiplier of any of\(2,3,5\) ;

```go
/**
 * @param num: An integer
 * @return: true if num is an ugly number or false
 */
func isUgly (num int) bool {
    if num <=0 {
        return false
    }else if num <= 5 {
        return true
    }
    
    //check if the num only has factor of 2,3,5
    for num % 2 == 0 {
        num = num/2
    }
    
    for num % 3 == 0 {
        num = num/3
    }    

    for num % 5 == 0 {
        num = num/5
    }
    
    return num == 1 
}
```

#### Description

Ugly number is a number that only have factors `2`, `3` and `5`.

Design an algorithm to find the _n_th ugly number. The first 10 ugly numbers are `1, 2, 3, 4, 5, 6, 8, 9, 10, 12...`

Note that `1` is typically treated as an ugly number.Have you met this question in a real interview?  YesProblem Correction

#### Example

If `n=9`, return `10`.

#### Challenge

O\(_n_ log _n_\) or O\(_n_\) time.

_这就是多链表Merge Sort的一个扩展题。对于任意一个ugly number - K, 2\*K, 3\*K, 和5\*K都是ugly number，所以说新的ugly number都是从已有的ugly number上，通过与{2,3,5}相乘而产生的。如果Ugly Number:_       

_1,         2,          3,           4,           5,           6,            8,         10,     ..............那么                      1\*2      2\*2        3\*2         4\*2         5\*2         6\*2         8\*2        10\*2  .............. \*2                             1\*3      2\*3        3\*3         4\*3         5\*3         6\*3         8\*3        10\*3  .............. \*3                             1\*5      2\*5        3\*5         4\*5         5\*5         6\*5         8\*5        10\*5  .............. \*5都是ugly number。只要不断把新产生的ugly number通过merge sort添加到原有的ugly number数组中就可以了，直到找到第N个。_

easier to understand way is to use hashmap and priority\_queue \(min-heap\),

every time we calculate the new prime number and push it into queue, queue will update the min-heap inside.

```cpp
class Solution {
public:

    class Compare{
        public:
            bool operator()(int a, int b){
                return a > b;
            }
    };
    
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        std:priority_queue<long int,vector<long int>,Compare> q;
        unordered_set<long int> s;
        vector<int> base= {2,3,5};
        for(auto b : base){
            q.push(b);
            s.insert(b);
        }
        
        long int tmp = 1;
        for(int i = 1; i < n; i++){
            if (q.empty()) break;
            
            tmp = q.top(); q.pop();
            for(auto b : base){
                
                //very important !!!
                //when tmp*b is overflow, we should stop the calculation
                //we simply popup the number//
                //which mean we just return the maximum prime number
                if (tmp*b >= INT_MAX) continue;
            
                if (s.find(tmp* b) == s.end()){
                    s.insert(tmp*b);
                    q.push(tmp*b);
                }
            }
        }
        return tmp;
    }
};
```

_A better solution with DP_ algorithm_,_

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int mn = min(m2, min(m3, m5));
            if (mn == m2) ++i2;
            if (mn == m3) ++i3;
            if (mn == m5) ++i5;
            res.push_back(mn);
        }
        return res.back();
    }
};
```

\_\_

