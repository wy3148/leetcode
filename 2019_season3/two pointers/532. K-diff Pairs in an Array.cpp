

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ret = 0;
        
        //时间复杂度n * log(n)
        for(int i = 0; i < nums.size(); i++){
            
            if (i > 0 && nums[i] == nums[i -1]) continue;
            
            int l = i;
            int r = nums.size() -1;

            while(l < r){
                if (nums[r] - nums[l] == k){
                    ret++;

                    l++;
                    while(l < nums.size()){
                        if (nums[l] == nums[l-1]){
                            l++;
                        }else{
                            break;
                        }
                    }

                    r--;
                    while(r >=0 ){
                        if (nums[r] == nums[r+1]){
                            r--;
                        }else{
                            break;
                        }
                    }                
                }else if (nums[r] - nums[l] > k){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ret;
    }
};
