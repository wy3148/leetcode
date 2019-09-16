// 345. Reverse Vowels of a String
// DescriptionHintsSubmissionsDiscussSolution
// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:

// Input: "hello"
// Output: "holle"
// Example 2:

// Input: "leetcode"
// Output: "leotcede"
// Note:
// The vowels does not include the letter "y".

class Solution {
public:
    
    bool isVowel(char c){
        if ( c == 'a' || c == 'A' || 
           c == 'E' || c == 'e' || 
           c == 'I' || c == 'i' ||
           c == 'O' || c == 'o' ||
            c == 'U' | c == 'u'){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        
        //A, E, I, O, U
        //two pointers
        
        int l = 0;
        int r = s.size() - 1;
        
        while ( l < r ){
            
            //
            while(l < s.size()){
                if (!isVowel(s[l])){
                    l++;
                }else{
                    break;
                }
            }
            
            //
            while(r >= 0){
                if (!isVowel(s[r])){
                    r--;
                }else{
                    break;
                }
            }
            
            if (l < r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        
        return s;
    }
};