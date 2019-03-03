# 447 search in a big sorted array

Given a big sorted array with positive integers sorted by ascending order. The array is so big so that you can not get the length of the whole array directly, and you can only access the kth number by `ArrayReader.get(k)` \(or ArrayReader-&gt;get\(k\) for C++\). Find the first index of a target number. Your algorithm should be in O\(log k\), where k is the first index of the target number.

Return -1, if the number doesn't exist in the array.

Example

Given `[1, 3, 6, 9, 21, ...]`, and target = `3`, return `1`.

Given `[1, 3, 6, 9, 21, ...]`, and target = `4`, return `-1`.

Notes:

we should try to find the index of element which is bigger than the target, then we use the binary search to find the actual position.

when try to find the index, we can start from index 1, then index \* 2 =2,

then index \* 2 = 4, 8,16 .... find the index &gt; target value.

