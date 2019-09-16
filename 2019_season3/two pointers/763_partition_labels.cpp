
// 763. Partition Labels
// DescriptionHintsSubmissionsDiscussSolution
// A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

// Example 1:
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
// Note:

// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        unordered_map<char,int> p;
        
        //the most right position for each character
        //"ababcbacadefegdehijhklij"
        for(int i = 0; i < S.size(); i++){
            p[S[i]] = i;
        }
        
        vector<int> ret;
        
        int l = 0;
        int r = 0;
        
        for(int i = 0; i < S.size(); i++){
            
            //a的最右位置
            r = max(r, p[S[i]]);
            
            //如果当前位置是 S[i]的最右侧位置，那么可以分割字符串了
            //下一个位置更新left 位置；字符为 i + 1 处 的字符
            if (i == r){
                ret.push_back(i - l + 1);
                l = i + 1;
            }
        }
        
        return ret;
    }
};
