// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

// The lock initially starts at '0000', a string representing the state of the 4 wheels.

// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

// Example 1:
// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation:
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".
// Example 2:
// Input: deadends = ["8888"], target = "0009"
// Output: 1
// Explanation:
// We can turn the last wheel in reverse to move from "0000" -> "0009".
// Example 3:
// Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
// Output: -1
// Explanation:
// We can't reach the target without getting stuck.
// Example 4:
// Input: deadends = ["0000"], target = "8888"
// Output: -1
// Note:
// The length of deadends will be in the range [1, 500].
// target will not be in the list deadends.
// Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.


//Warning!!!!!!!!有bug
//错误算法
class Solution {
public:
    
    //有点像word ladder的思路
    //
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        
        vector<char> base = {'0','1','2','3','4','5','6','7','8','9'};
        
        //each character from 0 to 9
        //
        map<string,bool> dead;
        for(auto v: deadends){
            dead[v] = true;
        }
        if (dead[target]) return -1;
        
        queue<string> q;
        q.push("0000");
        map<string,bool> visited;
        visited["0000"] = true;
        int steps = -1;
        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i =0; i < size; i++){
                
                string tmp = q.front(); q.pop();
                if (tmp == target){
                    return steps;
                }
                
                for(int pos = 0; pos < 4; pos++){
                    string next(tmp);
                    for(int c = 0; c < 10; c++){
                        next[pos] = base[c];
                        if (next != tmp && visited[next] == false && dead[next] == false){
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

//Still WRONG !!!!XXXX
class Solution {
public:
    
    //有点像word ladder的思路
    //
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        
        vector<char> base = {'0','1','2','3','4','5','6','7','8','9'};
        
        //each character from 0 to 9
        //
        map<string,bool> dead;
        for(auto v: deadends){
            dead[v] = true;
        }
        if (dead[target]) return -1;
        
        queue<pair<string,int>> q;
        q.push({"0000",0});
        map<string, bool> visited;
        visited["0000"] = true;
        
        while(!q.empty()){
                auto tmp = q.front(); q.pop();
                if (tmp.first == target){
                    return (tmp.second + 1);
                }
            
                for(int pos = 0; pos < 4; pos++){
                    string next(tmp.first);
                    for(int c = 0; c < 10; c++){
                        next[pos] = base[c];
                        if (next != tmp.first && dead[next] == false && visited[next] == false){
                            q.push({next,tmp.second + 1});
                            visited[next] = true;
                        }
                    }
                }
        }
        return -1;
    }
};


//正确的BFS算法
//the key part of this problem is about how to move the wheel,
//each time for each move, we can only increase the number or decrease number by 1; 

//so if '0' is the initial value, the next value could be '2', or '9';
//After understanding the rules of opening box, we use 'by level' bfs to search the target

// so '0000', its next move could be 8 different values
// 1000,0100,0010,9000,...etc
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto& v : deadends){
            dead.insert(v);
        }
        if (dead.find("0000") != dead.end() || dead.find(target) != dead.end()){
            return -1;
        }
        
        queue<string> q;
        q.push("0000");
        unordered_map<string, bool> visited;
        visited["0000"] = true;
        
        int move = 0;
        while(!q.empty()){
            
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                string cur = q.front(); q.pop();
                
                if (cur == target) return move;
                
                for(int c = 0; c < 4; c++){
                    string tmp(cur);
                    //each wheel can rotate two directions
                    tmp[c] = cur[c] + 1;
                    if (tmp[c] > '9'){
                        tmp[c] = '0';
                    }
                    if (visited[tmp] == false && dead.find(tmp) == dead.end()){
                        q.push(tmp);
                        visited[tmp] = true;
                    }
                    tmp[c] = cur[c] - 1;
                    if (tmp[c] < '0'){
                        tmp[c] = '9';
                    }
                    if (visited[tmp] == false && dead.find(tmp) == dead.end()){
                        q.push(tmp);
                        visited[tmp] = true;
                    }                   
                }
            }
            move++;  
        }
        return -1;
    }
};
