
// 12. Integer to Roman
// DescriptionHintsSubmissionsDiscussSolution
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:

// Input: 3
// Output: "III"
// Example 2:

// Input: 4
// Output: "IV"
// Example 3:

// Input: 9
// Output: "IX"
// Example 4:

// Input: 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 5:

// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


class Solution {
public:
    string intToRoman(int num) {            
        string digitStr[] =  {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
        //arrays is 13 len
        int  values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        string ret;
        
        //依次从i 0开始，从大的数值开始递减计算
        for(int i = 0; i < 13; i++){
            
            while(num >= values[i]){
                ret += digitStr[i];
                num -= values[i];
            }
        }
        return ret;
    }
};


///另外一种常规思维，函数递归调用的方法
//写法看上去复杂一些，但是逻辑也算是比较简单


class Solution {
public:
    
    unordered_map<int,string> data; 
    Solution(){
        data[1] = "I";
        data[4] = "IV";
        data[5] = "V";
        data[9] = "IX";
        data[10] = "X";
        data[40] = "XL";
        data[50] = "L";
        data[90] = "XC";
        data[100] = "C";
        data[400] = "CD";
        data[500] = "D";
        data[900] = "CM";
        data[1000] = "M";       
    }
    
    string intToRoman(int num) {
        string ret;
        if (num <= 0) return ret;
        
        if (num >= 1000){
            int n = num / 1000;
            for(int i = 0; i < n; i++){
                ret += data[1000];
            }
            ret += intToRoman(num % 1000);
        }else if (num >= 900 && num < 1000){
            ret += data[900];
            ret += intToRoman(num - 900);
        }else if (num >= 500 && num < 900){
            ret += data[500];
            ret +=intToRoman(num - 500);
        }else if (num >= 400 && num < 500){
            ret += data[400];
            ret +=intToRoman(num - 400);
        }else if( num >= 100 && num < 400){
            int n = num / 100;
            for(int i = 0; i < n; i++){
                ret += data[100];
            }
            ret += intToRoman(num % 100);
        }else if(num >=90 && num < 100){
            ret += data[90];
            ret += intToRoman(num - 90);
        }else if(num >= 50 && num < 90){
            ret += data[50];
            ret += intToRoman(num - 50);
        }else if(num >= 40 && num < 50){
            ret += data[40];
            ret += intToRoman(num - 40);
        }else if(num >= 10 && num < 40){
            int n = num / 10;
            for(int i = 0; i < n; i++){
                ret += data[10];
            }
            ret += intToRoman(num % 10);
        }else if(num >= 1 && num < 10){
            if (num == 9){
                ret += data[9];
            }else if (num >= 5 && num < 9){
                ret += data[5];
                ret += intToRoman(num - 5);
            }else if(num == 4){
                ret += data[4];  
            }else{
                for(int i = 0;i < num; i++){
                    ret += data[1];
                }
            }
        }
        return ret;
    }
};

