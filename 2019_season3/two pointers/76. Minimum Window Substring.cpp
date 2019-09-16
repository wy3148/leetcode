// 76. Minimum Window Substring
// DescriptionHintsSubmissionsDiscussSolution
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> data;
        int ret = INT_MAX;
        string str;
        
        for(auto c : t){
            data[c]++;
        }
        
        //the numbers of distinct characters
        int count = data.size(); 
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            while (j < s.size()){
                data[s[j]]--;
                if (data[s[j]] == 0){
                    count--;
                }
                j++; // j++ here , difference when j++ after break
                
                if (count == 0){
                    if (ret > j - i){
                        ret = j - i;
                        
                        //substring str from i to j
                        str = s.substr(i,j);
                    }
                    break;
                }
            }
            
            //move i to its next pos
            if (data[s[i]] == 0){
                count++;
            }
            data[s[i]]++;
        }
        
        return str;
    }
};