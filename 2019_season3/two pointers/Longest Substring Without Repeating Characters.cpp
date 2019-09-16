

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        
        int ret = 0;
        
        //255 char position
        vector<int> pos(255,-1);
        //
        int left  = 0;

        //pwwekw
        for(int i = 0;i < s.size(); i++){
            
            //>=left,说明字符曾经出现了left的右半位置；重复了
            if (pos[s[i]] >= left)  left = pos[s[i]] + 1;
            
            pos[s[i]] = i;
            
            //ab, as default value is -1// i -left is the actual length
            ret = max(ret, i - left + 1);
        }
        return ret;
    }
};
