---
description: 'https://www.lintcode.com/problem/heapify/description'
---

# 130 Heapify

#### Description

Given an integer array, heapify it into a min-heap array.For a heap array A, A\[0\] is the root of heap, and for each A\[i\], A\[i \* 2 + 1\] is the left child of A\[i\] and A\[i \* 2 + 2\] is the right child of A\[i\].

Have you met this question in a real interview?  YesProblem Correction

#### Clarification

**What is heap?**

* Heap is a data structure, which usually have three methods: push, pop and top. where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.

  
**What is heapify?**

* Convert an unordered integer array into a heap array. If it is min-heap, for each element A\[i\], we will get A\[i \* 2 + 1\] &gt;= A\[i\] and A\[i \* 2 + 2\] &gt;= A\[i\].

  
**What if there is a lot of solutions?**

* Return any of them.

#### Example

Given \[3,2,1,4,5\], return \[1,2,3,4,5\] or any legal heap array.

#### Challenge

O\(n\) time complexity

Solution: 

the part of internal implementation of priority queue, that compose the min-heap. 

the basic idea is the 'shiftup' function, when a new element insert into the last position of the array,

it need to compare to the parent node.  parent  = \(pos -2 \)/2 is used to calculate the parent position.

```cpp
class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
        if(A.size() == 0) return;
        vector<int> res(A.size(), 0);
        int size = 0;
        
        for(auto v : A){
            if (size == 0 ){
                res[size] = v;
            }else{
                //shiftup, the last element and parent element
                //compare, and if less, shift up the parent postion
                //and interate until to the top minimum
                res[size] = v;
                int pos = size;
                while(pos > 0 ){
                    int parent = (pos - 1) /2;
                    if (res[pos] < res[parent]){
                        swap(res[pos],res[parent]);
                        pos = parent;
                    }else{
                        break;
                    }
                }
            }
            size++;
        }
        
        for(int i = 0; i < A.size(); i++){
            A[i] = res[i];
        }
    }
};
```

