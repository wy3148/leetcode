
//基本的strstr方法实现
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int l1 = haystack.size();
        int l2 = needle.size();
        if (l2 == 0) return 0;
        
        for(int i = 0; i <= l1 - l2; i++){    
            int s = i;
            bool match = true;
            for(int j = 0; j < l2; j++){
                if (haystack[s] == needle[j]){
                    s++;
                }else{
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        return -1;
    }
};
