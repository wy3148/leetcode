// 43. Multiply Strings
// DescriptionHintsSubmissionsDiscussSolution
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
// Note:

// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.


//123
//456

// i =2 , j = 2;  ret[5] = 8; ret[4] = 1; 3*6 = 18;
//


// 字符串num1的长度是m，字符串num2的长度是n，两个字符串相乘的结果的长度肯定不会超过m+n；因此结果ret的大小申请为m+n，并将每一个字符都初始化为0；

// 然后根据竖式计算的计算方法，可以得出
// ret[i+j+1]=((ret[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0')) %10 +'0';
// 其中 (ret[i + j + 1] - '0')是之前的进位。
// ret[i + j] = ( (ret[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0')/10; 
// 为进位

// 因为最开始ret申请的大小为n+m，如果num1和num2比较小的话，前边肯定有0空余，因此需要从第一个不为'0'的位置开始截取出返回结果ret。



class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        
        if (m == 0 || n == 0) return 0;
        
        //m 位 * n 位 最多就是 m+n位的结果
        string ret(m + n, '0');
        
        //123 * 456
        //i = 2,j =2; ret[2 + 2 + 1] = ret[5] = 8
        //
        for(int i = m -1; i >=0; i--){
            for(int j = n - 1; j >=0; j--){
                int sum = ret[i +j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
                ret[i +j + 1] =  (sum % 10) + '0';
                ret[i + j] += sum / 10;
            }
        }
        for(int i = 0; i < ret.size(); i++){
            if (ret[i] != '0') return ret.substr(i);
        }
        return "0";
    }
};
