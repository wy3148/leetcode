//sort array
//算法和 3um = target 思路比较类似

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int l = i + 1;
            int r = nums.size() - 1;
            
            while(l < r){

                int s = nums[i] + nums[l] + nums[r];
                
                if (s == target){
                    return s;
                }else if (s > target){
                    if (diff > s- target){
                        diff = s- target;
                        sum = s;
                    }
                    r--;
                }else{
                    if (diff > target - s){
                        diff = target -s;
                        sum = s;
                    }
                    l++;
                }
            }
        }
        return sum;
    }
};