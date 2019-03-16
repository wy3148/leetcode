---
description: 'https://www.lintcode.com/problem/flatten-2d-vector/description'
---

# 601 Flatten 2D Vector



#### Description

Implement an iterator to flatten a 2d vector.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given 2d vector =

```text
[
  [1,2],
  [3],
  [4,5,6]
]
```

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: `[1,2,3,4,5,6]`.  


```cpp
class Vector2D {

private:
    vector<int> data;
    int pos;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        pos = 0;
        for(auto v : vec2d){
            for(auto d : v){
                data.push_back(d);
            }
        }
    }
    
    int next() {
        // Write your code here
        return data[pos++];
    }

    bool hasNext() {
        // Write your code here
        return pos < data.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
```

also we can use 'queue',

```cpp
class Vector2D {
public:

    std::queue<int> q;
    
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        for(auto a : vec2d){
            for(auto v : a){
                q.push(v);
            }
        }
    }
    
    int next() {
        if (!q.empty()){
            int t = q.front();
            q.pop();
            return t;
        }
        return -1;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
```

