---
description: 'https://www.lintcode.com/problem/implement-strstr/'
---

# strstr

#### Description

For a given source string and a target string, you should output the **first** index\(from 0\) of target string in source string.

If target does not exist in source, just return `-1`.

#### Clarification

Do I need to implement KMP Algorithm in a real interview?

* Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure you confirm with the interviewer first.

#### Example

If source = `"source"` and target = `"target"`, return `-1`.

If source = `"abcdabcdefg"` and target = `"bcd"`, return `1`.

#### Challenge

O\(n2\) is acceptable. Can you implement an O\(n\) algorithm? \(hint: _KMP_\)

c++ strings.substr\(\),if the second length parameter exceeds the length of source string, it will return to end of string.

```cpp
class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        if(target == source || target.length() == 0) return 0;
        int sLen = source.length();
        int tLen = target.length();
        
        for(int i = 0; i < sLen; i++){
            string s = source.substr(i, tLen);
            if (s == target) return i;
        }
        return -1;
    }
}
```

