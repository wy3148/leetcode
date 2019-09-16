



//Warning!!!!!!!!!!!
// !!!!!!!!!!
// !!!!!!!!!!
// Following function is having bug
class Solution {
public:

    bool canForm(string a, string b){
        if (a.size() < b.size()) return false;
        if (a.size() == b.size()){
            if (a == b ) return true;
            return false;
        }
        
        //abc : ac
        //
        int p = 0; //a position
        int l = 0;
        
        //we need to maintain the relative order of characters in the original string
        //
        for(l = 0; l < b.size(); l++){   
            if (p < a.size()){
                if (a[p] == b[l]){
                    p++;
                    continue;
                }else{
                    while(p < a.size()){
                        if (a[p] == b[l]){
                            break;
                        }else{
                            p++;
                        }
                    }
                }   
            }else{
                break;
            }
        }
        return l == b.size() ? true : false;
    }
    
    string findLongestWord(string s, vector<string>& d) {
        string ret;
        for(auto str :d ){
            if (canForm(s, str)){
                if (str.size() > ret.size() || str.size() == ret.size() && str.compare(ret) < 0){
                    ret = str;
                }
            }
        }
        return ret;
    }
};