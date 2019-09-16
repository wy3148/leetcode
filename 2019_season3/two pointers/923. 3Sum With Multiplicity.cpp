// 923. 3Sum With Multiplicity
// DescriptionHintsSubmissionsDiscussSolution
// Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

// As the answer can be very large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (A[i], A[j], A[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
// Example 2:

// Input: A = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation: 
// A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.



//下面算法不正确！！！！！Warning !!!!!!!!xxxxx!!!!xxx!!!

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        
        if (A.size() == 0) return 0;
        sort(A.begin(),A.end());
        int ret = 0;
        
        //和3sum的核心区别是，本道题目是不能去重的
        for(int i = 0; i < A.size(); i++){
            
            int l = i + 1;
            int r = A.size() - 1;
            int t = target - A[i];
            
            while(l < r){
                if (A[l] + A[r] == t){
                    ret++;
                    
                    int left = l + 1;
                    while (left < r){
                        if (A[left] == A[left - 1]){
                            ret++;
                            left++;
                        }else{
                            break;
                        }
                    }
                    int right = r - 1;
                    while (l < right){
                          if (A[right] == A[right + 1]){
                            ret++;
                            right--;
                        }else{
                            break;
                        }                      
                    }
                    l = left;
                    r = right;
                }else if (A[l] + A[r] > t){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ret;
    }
};



//warning！！！！！
//下面算法是正确，但是时间复杂度过高！！！
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        
        if (A.size() == 0) return 0;
        sort(A.begin(),A.end());
        int ret = 0;
        
        //和3sum的核心区别是，本道题目是不能去重的
        for(int i = 0; i < A.size(); i++){
            int l = i + 1;
            int r = A.size() - 1;
            int t = target - A[i];
            
            while(l < r){
                if (A[l] + A[r] == t){
                    ret++;
                    
                    int left = l + 1;
                    while (left < r){
                        if (A[left] == A[left - 1]){
                            ret++;
                            left++;
                        }else{
                            break;
                        }
                    }
                    int right = r - 1;
                    while (l < right){
                          if (A[right] == A[right + 1]){
                            ret++;
                            right--;
                        }else{
                            break;
                        }                      
                    }
                    l++;
                    r--;
                }else if (A[l] + A[r] > t){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ret;
    }
};