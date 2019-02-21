# 136 Palindrome partition

#### Description

中文English

Given a string _s_, partition _s_ such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given s = `"aab"`, return:

```text
[
  ["aa","b"],
  ["a","a","b"]
]
```

#### Related Problems

"aab",  a string with len n, we have 'n-1' positions for partitions,

when start from index 0, we partition the string as 

'a, ab'

as 'a' is palindrome, we continuously partition the 'ab', the same login.

once the partition position is to the end of string, it stops.

then we need to 'backtrack'.

```cpp
class Solution {
public:
    
    bool isPalindrome(string& s){
        int len = s.length();
        if (len == 0) return false;
        int i = 0;
        int j = len - 1;
        while(i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void dfs(vector<vector<string>>& res,vector<string>& list,
    string& s, int pos){
        
        if (pos == s.length()){
            res.push_back(list);
        }
        
        
        // aab
        //  index 0 ~ 1 : a , ab; 
        // ab, a, b
        //
        for(int i = pos + 1; i <= s.length(); i++){
            string substr = s.substr(pos, i - pos);
            if (!isPalindrome(substr)) {
                continue;
            }
            list.push_back(substr);
            dfs(res,list,s,i);
            list.pop_back();
        }
    }

    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here
        
        vector<vector<string> > result;
        if (s.empty()) return result;
        
        vector<vector<string>> res;
        vector<string> list;
        
        dfs(res,list,s,0);
        return res;
    }
};
```



#### Description

中文English

Given a string _s_, cut _s_ into some substrings such that every substring is a palindrome.

Return the **minimum** cuts needed for a palindrome partitioning of _s_.Have you met this question in a real interview?  YesProblem Correction

#### Example

Given s = `"aab"`,

Return `1` since the palindrome partitioning \["aa", "b"\] could be produced using _1_ cut.

#### Related Problems

[893. Longest Palindromic Substring II](https://www.lintcode.com/problem/longest-palindromic-substring-ii)[507. Wiggle Sort II](https://www.lintcode.com/problem/wiggle-sort-ii)[136. Palindrome Partitioning](https://www.lintcode.com/problem/palindrome-partitioning)[200. Longest Palindromic Substring](https://www.lintcode.com/problem/longest-palindromic-substring)



