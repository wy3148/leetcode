11. Container With Most Water

//try to make width as large as possible
//then we decrease the width,we try to find the higher height
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right){
            int container = (right - left) *  (height[left] < height[right] ? height[left]: height[right]);  
            ret = max(ret, container);
            
            //left 低一些, left++,尽量高一些
            if (height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ret;
    }
};
