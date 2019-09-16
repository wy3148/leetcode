

// 845. Longest Mountain in Array
// DescriptionHintsSubmissionsDiscussSolution
// Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

// B.length >= 3
// There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
// (Note that B could be any subarray of A, including the entire array A.)

// Given an array A of integers, return the length of the longest mountain. 

// Return 0 if there is no mountain.

// Example 1:

// Input: [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
// Example 2:

// Input: [2,2,2]
// Output: 0
// Explanation: There is no mountain.
// Note:

// 0 <= A.length <= 10000
// 0 <= A[i] <= 10000
// Follow up:

// Can you solve it using only one pass?
// Can you solve it in O(1) space?


class Solution {
public:
    int longestMountain(vector<int>& A) {
        //算法思路 中心点向两边方向扩散
    
        int ret = 0;
        
        //[2,1,4,7,3,2,5]
        
        for(int i = 0; i < A.size(); i++){      
            int prev = A[i];
            int l = i - 1;
            int r = i + 1;
            int tmp = 1;
            bool hasLeft = false;
            bool hasRight = false;
            while( l >= 0){
                if (A[l] < prev){
                    prev = A[l];
                    l--;
                    tmp++;
                    hasLeft = true;
                }else{
                    break;
                }
            }
            
            prev = A[i];
             while(  r < A.size()){
                if (A[r] < prev){
                    prev = A[r];
                    r++;
                    tmp++;
                    hasRight = true;
                }else{
                    break;
                }
            }
            
            if (hasLeft && hasRight){
                ret = max(ret, tmp);
            }
        }
        
        //每个中心点 都要往两边走，有n个点，每次都要遍历n次
        //时间复杂度应该是n^2
        return ret;
    }
};



