
// 844. Backspace String Compare
// DescriptionHintsSubmissionsDiscussSolution
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int len1 = 0;
        int len2 = 0;
        
        for(int i = 0;i < S.size(); i++){
            
            if (S[i] != '#'){
                S[len1] = S[i];
                len1++;
                continue;
            }else{
                len1--;
            }
        }
        
        for(int i = 0;i < T.size(); i++){
            
            if (T[i] != '#'){
                T[len2] = T[i];
                len2++;
                continue;
            }else{
                len2--;
            }
        }
        
        if (len1 != len2) return false;
        int i = 0;
        while( i < len1){
            if (S[i] != T[i]) return false;
            i++;
        }
        return true;
    }
};
