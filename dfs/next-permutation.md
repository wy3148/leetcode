# next permutation



[  
Back](https://www.lintcode.com/problem/)52. Next PermutationFollow

* Description
* Leaderboard
* Note
* Discuss
* Solution
* * My Submissions
* Open IDE

#### Description

中文English

Given a list of integers, which denote a permutation.

Find the next permutation in ascending order.

The list may contains duplicate integers.Have you met this question in a real interview?  YesProblem Correction

#### Example

Example 1:

```text
Input:[1]
Output:[1]
```

Example 2:

```text
Input:[1,3,2,3]
Output:[1,3,3,2]
```

Example 3:

```text
Input:[4,3,2,1]
Output:[1,2,3,4]
```

对于不了解全排列是什么的同学，可以点击此处进行查看[全排列-百度百科](http://baike.baidu.com/link?url=uo349BKtv_Pd0BmEzLXFpDAsFDs8puwqIsE-JhXzFIXGQDf66vWoxcG4Ao5OU6ZVNF4ywm2qXf32YeoQSW71TK)。

对于这道题目来说，其目的在于对于给定的一个全排列，求解其“下一个”全排列。即将所有全排列按照字典序排序后之后的下一个全排列，如果本身已经是最后一个的话，则返回第一个全排列。

那么我们对于几个不同的全排列来看其存在怎样的性质

1,2,3 → 1,3,2

1,2,3,4 -&gt; 1,2,4,3

1,2,3,5,4 -&gt; 1,2,4,3,5

不难发现，如同一般十进制数的进位一样，“下一个”这种类似于“+1”的操作通常只会影响到全排列的最后若干位，即前若干位是会保持不变的。

如对于全排列1,2,3,5,4来说，因为1,2,3,5,4并不是1开头的所有全排列中字典序最大的一个，所以它的下一个全排列的第一个数字仍然是1，我们只需要考虑2,3,5,4的下一个全排列是多少即可（然后在这个全排列的基础上最前面写下1即可得到原来全排列的下一个全排列）。

同理，我们可以知道2,3,5,4的下一个全排列的第1个数字一定是2，所以我们只需要求解3,5,4的下一个全排列。

但是对于3,5,4来说，它已经是所有3开头的全排列中字典序最大的一个了（3,5,4&gt;3,4,5），所以需要发生“进位”的操作，即令3变为字典中的下一个元素4，然后将剩下的数字变为最小的排列——3,5，也就是说3,5,4的下一个全排列是4,3,5。

抽象的来说，如果对于一个全排列a1,a2,a3,...,ak来说，如果满足a1 &lt; a2 ≥ a3 ≥ a4 ... ≥ ak（所有a1开头的全排列中字典序最大的情况），就说明这个全排列的下一个全排列不能再由a1开头，而是a1在字典中的下一个元素aj（即最小的满足aj &gt; a1且2 ≤ j ≤ k的aj），由于任何aj开头的全排列都大于a1开头的全排列，所以我们寻找的全排列是aj开头的最小的全排列。

也就是说，这道题目的做法变成了在给出的全排列中，寻找一个p，要求其满足ap &lt; ap+1 ≥ ap+2 ≥ ap+3 ... ≥ an，然后只需将ap变成ap+1..an中最小的大于ap的数字，然后将剩下的数字按照从小到大的顺序放置即可（根据我们之前的讨论，可以很容易的知道a1..ap-1都不会产生变化）。

特别的，对于不存在这样的i时，即a1&gt;=a2&gt;=a3&gt;=...&gt;=an，我们要注意进行特殊处理。

1,3,2,3

find the p = index 3,

on reverse direction, find the first element which is big than P - 1 

13 3 2

```cpp
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        
       if (nums.size() <= 1) {
            return nums;
        }
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) {
            i--;
        }
        
        if (i) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i - 1]) {
                j--;
            }
            swap(nums[i - 1], nums[j]);
        }
        
        reverse(nums.begin() + i, nums.end());
        return nums;
    }
};
```

