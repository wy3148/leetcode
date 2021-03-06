---
description: 'https://www.lintcode.com/problem/hash-function/description'
---

# 128 hash function

#### Description

In data structure Hash, hash function is used to convert a string\(or any other type\) into an integer smaller than hash size and bigger or equal to zero. The objective of designing a hash function is to "hash" the key as unreasonable as possible. A good hash function can avoid collision as less as possible. A widely used hash function algorithm is using a magic number 33, consider any string as a 33 based big integer like follow:

hashcode\("abcd"\) = \(ascii\(a\) \* 333 + ascii\(b\) \* 332 + ascii\(c\) \*33 + ascii\(d\)\) % HASH\_SIZE 

                              = \(97\* 333 + 98 \* 332 + 99 \* 33 +100\) % HASH\_SIZE

                              = 3595978 % HASH\_SIZE

here HASH\_SIZE is the capacity of the hash table \(you can assume a hash table is like an array with index 0 ~ HASH\_SIZE-1\).

Given a string as a key and the size of hash table, return the hash value of this key.f



```cpp
class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        
        //if we directly the use formula to calcuate the result
        //the result could be overflow, we need to use 'long'
        long sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum = (sum * 33 + key[i]) % HASH_SIZE;
        }
        return (int) sum;
    }
};
```



