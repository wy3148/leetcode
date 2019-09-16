
//注意一下不能直接 +/- 32 做大小写转换，可能数字 digit 0-9 +/- 32
//转换到字母
class Solution {
public:
    
    //alphanumeric
    bool isValid(char c){
        if (c >='a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >='0' && c <='9') return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        
        int l = 0;
        int r = s.size() - 1;
        
        while(l < r){
            
            while( l < s.size()){
                if (isValid(s[l])) break;
                l++;
            }        
            while( r >= 0){
                if (isValid(s[r])) break;
                r--;
            }
            
            if ( l < r){                
                if (s[l] == s[r] || s[l] >= 'a' && s[l] <='z' && s[l] - 32 == s[r] || 
                    s[l] >= 'A' && s[l] <='Z'&& s[l] + 32 == s[r]){
                    l++;
                    r--;
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
