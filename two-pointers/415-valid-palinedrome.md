---
description: 'https://www.lintcode.com/problem/valid-palindrome/description'
---

# 415 Valid Palinedrome

#### Description

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.Have you met this question in a real interview?  YesProblem Correction

#### Example

`"A man, a plan, a canal: Panama"` is a palindrome.

`"race a car"` is not a palindrome.

#### Challenge

O\(n\) time without extra memory.

#### Related Problems

Solution:

should ignore the character if it's not  alphanumeric

```cpp
class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    
    
    bool isalphanumber(char c){
        return (c >= 'a' && c <= 'z' || 
                c >= 'A' && 
                c <= 'Z' ||
                c >= '0' && 
                c <= '9');
    }
    
    bool isPalindrome(string &s) {
        // write your code here
        if (s.length() == 0) return true;
        
        int start = 0;
        int end = s.length() -1; 
        const char* str = s.c_str();
        
        //"A man, a plan, a canal: Panama"
        //alphanumeric
        while(start < end){
            while(start <= end){
                if(isalphanumber(str[start])){
                    break;
                }else{
                    start++;
                    continue;
                }
            }
            
            while(start <= end){
                if (isalphanumber(str[end])){
                    break;
                }else{
                    end--;
                    continue;
                }
            }
            
            if (isalphanumber(str[start]) == false && 
            isalphanumber(str[end]) == false) continue;
            
            if (isalphanumber(str[start]) && 
            isalphanumber(str[end])){
                if (str[start] == str[end]  || 
                str[start] == str[end] + 32 || 
                str[start] == str[end] - 32){
                    start++;
                    end--;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
};
```

