
//优先级队列，或者two pointers来实现
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::priority_queue<int,vector<int>, std::greater<int>> q;
        
        vector<int> ret;
        if (A.size() == 0) return ret;
        
        for(auto v: A){
            q.push(v * v);
        }
        
        while(!q.empty()){
            ret.push_back(q.top());
            q.pop();
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.size() == 0){
            return {};
        }
        
        //数组 A 排序，最小值可能为负，平方后可能更大
        vector<int>ret(A.size(), 0);
        int l = 0;
        int r = A.size() - 1;
        int count = A.size() - 1;
        
        while (count >= 0){
        
            //从数组的最后一位开始，依次放入平方值比较大的那一个；
            
            //放左值，
            if (A[l] * A[l] >= A[r]*A[r]){
                ret[count]= A[l] * A[l];
                l++;
            }else{
                //放右值
                ret[count]= A[r] * A[r];
                r--;              
            }
            count--;
        }
        return ret;
    }
};
