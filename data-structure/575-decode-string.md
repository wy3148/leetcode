---
description: 'https://www.lintcode.com/problem/decode-string/description'
---

# 575 Decode String

Description

Given an expression `s` includes numbers, letters and brackets. Number represents the number of repetitions inside the brackets\(can be a string or another expression\)．Please expand expression to be a string.Have you met this question in a real interview?  YesProblem Correction

#### Example

s = `abc3[a]` return `abcaaa`  
s = `3[abc]` return `abcabcabc`  
s = `4[ac]dy`, return `acacacacdy`  
s = `3[2[ad]3[pf]]xyz`, return `adadpfpfpfadadpfpfpfadadpfpfpfxyz`

#### Challenge

Can you do it without recursion?

the recursion way is to parse the string, once it is a number, we take \[ xxx\] as a new substring,

and recursively call the function again.

```cpp
class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        string res;
        if (s.length() == 0) return res; 
        
        for (int i = 0; i < s.length(); i++){
            
            if ( s[i] >= 'A' && s[i] <= 'Z' ||
            s[i] >= 'a' && s[i] <= 'z'){
                string t;
                t.push_back(s[i]);
                res += t;
            }else if (s[i] >= '1' && s[i] <= '9'){
                //repeat
                int count;
                int j;
                for (j = i + 1; j < s.length(); j++){
                    if (s[j] == '['){
                        break;
                    }
                }
                string num(s.begin() + i, s.begin() + j);
                count = std::stoi(num);
                
                // cout << "got count:" << count << "\n";
                int stack = 1;
                int k;
                for(k = j + 1; k < s.length(); k++){
                    if (s[k] == ']'){
                        stack--;
                        if (stack == 0) break;
                    }else if(s[k] == '['){
                        stack++;
                    }
                }
                
                string express(s.begin() + j + 1, s.begin() + k);
                
                // cout << "got substring:" << express << "\n";
                
                string substr = expressionExpand(express);
                
                while (count > 0 ){
                    res += substr;
                    count--;
                }
                
                //relocate the position of i
                i = k;
            }else if (s[i] == '['){
                //comes to here for special case [abc]d,
                //in this case, the [abc] is not repeated, should be
                //ignored
                int stack  = 1;
                int j;
                for(j = i+1; j < s.length(); j++){
                    if (s[j] == ']'){
                        stack--;
                        if (stack == 0) break;   
                    }else if(s[j] == '['){
                        stack++;    
                    }
                }
                
                //relocate the position of i
                i = j;
            }
        }
        
        // cout << "return string:" << res << "\n";
        return res;
    }
};
```



Go version

```go
/**
 * @param s: an expression includes numbers, letters and brackets
 * @return: a string
 */
 import(
     "strconv"
)
 
func expressionExpand (s string) string {
    // write your code here
    
    str :=[]byte(s)
    var ret []byte
    
    i := 0
    for i < len(str) {
        
        if str[i] >= 'a' && str[i] <= 'z' ||
        str[i] >='A' && str[i] <='Z'{
            ret = append(ret,str[i])
            i++
            continue
        }else if str[i] >= '0' && str[i] <= '9'{
            j := i + 1 
            for j < len(str) && str[j] >= '0' && str[j] <= '9'{
                j++
            }
            
            repeat, _:= strconv.Atoi(string(str[i:j]))
            
            //stack to find the start, end position of []
            for j < len(str){
                if str[j] == '['{
                    break
                }
                j++
            }
            
            count := 1
            j++
            start := j
            
            for j < len(str){
                if str[j]==']'{
                    count--
                }else if str[j]=='['{
                    count++
                }
                if count == 0{
                    break
                }else{
                    j++
                }
            }
            
            newstr  := expressionExpand(string(str[start:j]))
            var tmpStr string
            for repeat > 0{
                tmpStr += newstr
                repeat--
            }
            
            ret  = append(ret,[]byte(tmpStr)...)
            
            //move i postion to next character of ']'
            i = j + 1
            continue
        }else if str[i] =='['{
            //special case [abcd]xyx , no number in front
            //means, no repat
            j := i + 1 
            count := 1 
            for j < len(str){
                if str[j] == ']'{
                    count--
                }else if str[j] == '['{
                    count++
                }
                
                if count == 0{
                    break
                }else{
                    j++
                }
            }
            
            i = j + 1 
            continue
        }
    }
    return string(ret)
}

```

in general, there are two different ways about loop,

```text
be noticed that
two different ways about loop

for i := 0; i < len(str); i++{

			i = j;
}
in this way, the next loop, 'i' will be j + 1 

for i < len(str){
	i = j;
	i++ //we have to call it manually 
}

```

