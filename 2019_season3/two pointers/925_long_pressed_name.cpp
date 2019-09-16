// 925. Long Pressed Name
// DescriptionHintsSubmissionsDiscussSolution
// Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

// You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

// Example 1:

// Input: name = "alex", typed = "aaleex"
// Output: true
// Explanation: 'a' and 'e' in 'alex' were long pressed.
// Example 2:

// Input: name = "saeed", typed = "ssaaedd"
// Output: false
// Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
// Example 3:

// Input: name = "leelee", typed = "lleeelee"
// Output: true
// Example 4:

// Input: name = "laiden", typed = "laiden"
// Output: true
// Explanation: It's not necessary to long press any character.

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.size() > typed.size()) return false;

        //"leelee", typed = "lleeelee"
        int len1= 0;
        for(int i = 0; i < typed.size(); i++){
            if (typed[i] == name[len1]){
                len1++;
            }else{
                if (len1 > 0 && typed[i] == name[len1-1]){
                    continue;
                }else{
                    return false;
                }
            }
        }
        
        //one case, there are extra characters in name not compared
        if (len1 < name.size()) return false;
        
        return true;
    }
};
