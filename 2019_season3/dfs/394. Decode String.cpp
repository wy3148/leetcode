


// 394. Decode String
// DescriptionHintsSubmissionsDiscussSolution
// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".



class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        
        string ret;
        while (i < s.size()){
            
            if (s[i] >='0' && s[i] <= '9'){      
                int pos = -1;
                int lastPos = -1;
                int count = 0;
                for (int j = i + 1; j < s.size(); j++){
                    if (s[j] == '['){
                        if (pos == -1){
                            pos = j;
                        }
                        count++;
                    }else if (s[j] == ']'){
                        count--;
                        if (count == 0){
                            lastPos = j;
                            break;
                        }
                    }
                }
                
                if (pos >= 0 && pos < s.size() && lastPos >= 0 && lastPos <s.size()){
                    int repeat = stoi(string(s.begin() + i , s.begin() + pos));
                    string tmp;
                    
//                     cout << "decode substr:" << string(s.begin() + pos + 1, s.begin() + lastPos) << "\n";
                       
                    string substr = decodeString(string(s.begin() + pos + 1, s.begin() + lastPos));
                    for(int r = 0; r < repeat; r++){
                        tmp +=substr;
                    }
                    ret += tmp;
                    
                    if (lastPos + 1 < s.size()){
                        ret += decodeString(string(s.begin() + lastPos + 1,s.end()));       
                    }
                }
                return ret;
            }else{
                ret.push_back(s[i]);
            }
            i++;
        }
        return ret;
    }
};
