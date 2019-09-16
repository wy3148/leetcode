// Description
// 中文
// English
// Write a method anagram(s,t) to decide if two strings are anagrams or not.

// Have you met this question in a real interview?  
// Clarification
// What is Anagram?

// Two strings are anagram if they can be the same after change the order of characters.
// Example
// Example 1:

// Input: s = "ab", t = "ab"
// Output: true
// Example 2:

// Input:  s = "abcd", t = "dcba"
// Output: true
// Example 3:

// Input:  s = "ac", t = "ab"
// Output: false
// Challenge
// O(n) time, O(1) extra space

// Related Problems

/**
 * @param s: The first string
 * @param t: The second string
 * @return: true or false
 */
func anagram (s string, t string) bool {
    // write your code here
    s1 := []byte(s)
    s2 := []byte(t)
    
    if len(s1) != len(s2){
        return false
    }
    
    m1 := make(map[byte]int)
    m2 := make(map[byte]int)
    
    for i := 0; i < len(s1); i++{
        m1[s1[i]]++
        m2[s2[i]]++
    }
    
    for _, v := range s1{
        if (m1[v] != m2[v]){
            return false
        }
    }
    return true
}
