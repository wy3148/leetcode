---
description: 'https://www.lintcode.com/problem/word-ladder/my-submissions'
---

# 120 word ladder

Description

中文English

Given two words \(start and end\), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

1. Only one letter can be changed at a time
2. Each intermediate word must exist in the dictionary

* Return 0 if there is no such transformation sequence.
* All words have the same length.
* All words contain only lowercase alphabetic characters.

Have you met this question in a real interview?  YesProblem Correction

#### Example

Given:  
start = `"hit"`  
end = `"cog"`  
dict = `["hot","dot","dog","lot","log"]`  


As one shortest transformation is `"hit" -> "hot" -> "dot" -> "dog" -> "cog"`,  
return its length `5`.

#### Related Problems

Notes:

using the "transform" function is not faster than the replace the character in each index from 'a' to 'z'.

using 'set' data structure helps to store/remove visited element.

```cpp
class Solution {
public:

    bool transform(string& start, string& dest){
        int len = start.length();
        int diff = 0;
        
        for(int i = 0; i  < len; i++){
            
            if (start[i] == dest[i]) continue;
            diff++;
            
            if (diff > 1) return false;
        }
        return true;
    }

    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {


                //"a"
                //"a"
                //["b"]
        if (start.length() == 0) return 0;
        if (start == end) return 1;
        
        queue<string> q;
        unordered_set<string> dataSet;
        
        for (auto v: dict){
            dataSet.insert(v);
        }
        
        q.push(start);
        int len = 2;
        
        //"hit" -> "hot" -> "dot" -> "dog" -> "cog"
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                string cur = q.front(); q.pop();
                for( int j = 0; j < cur.length(); j++){
                    string tmp = cur;
                    for (char c = 'a'; c <= 'z'; c++){
                        tmp[j] = c;
                        if (tmp == end) return len;
                        if (dataSet.find(tmp) != dataSet.end()){
                            q.push(tmp);
                            dataSet.erase(tmp);
                        }
                    }
                }
            }
            len++;
        }
        return 0;
    }
};
```

