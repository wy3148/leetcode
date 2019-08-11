// Back
// 212. Space Replacement
// Description
// 中文
// English
// Write a method to replace all spaces in a string with %20. The string is given in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.

// You code should also return the new length of the string after replacement.

// If you are using Java or Python，please use characters array instead of string.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input: string[] = "Mr John Smith" and length = 13
// Output: string[] = "Mr%20John%20Smith" and return 17
// Explanation:
// The string after replacement should be "Mr%20John%20Smith", you need to change the string in-place and return the new length 17.
// Example 2:

// Input: string[] = "LintCode and Jiuzhang" and length = 21
// Output: string[] = "LintCode%20and%20Jiuzhang" and return 25
// Explanation:
// The string after replacement should be "LintCode%20and%20Jiuzhang", you need to change the string in-place and return the new length 25.
// Challenge
// Do it in-place.

// Related Problems



class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // write your code here
        
        int count =0;
        int i= 0;
        while (i < length){
            if (string[i] == ' ') count++;
            i++;
        }
        
        //no spaces
        if (count == 0) return length;
        
        //new len of string
        int len = length + count * 2;
        
        //i ,j 的起始位置不一样，等于重用了数组
        //reuse the array 
        i = length - 1;
        int j = len - 1;
        
        while(i >=0){
            if (string[i] != ' '){
                string[j] = string[i];
                j--;
            }else{
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
                
            }
            i--;
        }
        return len;
    }
};
