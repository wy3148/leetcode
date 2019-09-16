// 567. Permutation in String
// DescriptionHintsSubmissionsDiscussSolution
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

// Example 1:

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
 

// Note:

// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].


//two pointers 和 slide window 的算法

func isClean(data map[byte]int) bool{
    for _, v := range data{
        if v != 0 {
            return false
        }
    }
    return true
}

func checkInclusion(s1 string, s2 string) bool {
    //s1 = "ab" s2 = "eidbaooo"
    
    if len(s1) > len(s2) {
        return false
    }
    
    data := make(map[byte]int)
    for _, v := range []byte(s1){
        data[v]++
    }
    
    for i := 0; i < len(s1); i++{
        
        //第一个窗口 window 范围 字符
        data[s2[i]]--
    }
    
    if isClean(data) {
        return true
    }

    //aeba
    left := 0
    for i := len(s1); i < len(s2); i++{
        data[s2[left]]++
        data[s2[i]]--
        left++
        
        //每次移动窗口的时候，检查是否所有字符归零，说明是排列组合
        if isClean(data) {
            return true
        }        
    }
    return false
}
