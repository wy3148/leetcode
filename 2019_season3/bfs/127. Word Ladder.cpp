// 127. Word Ladder
// DescriptionHintsSubmissionsDiscussSolution
// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: 0

// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.





class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if (wordList.size() == 0 || beginWord == endWord)return 0;
        
        set<string> data;
        for(auto& v : wordList){
            data.insert(v);
        }
        data.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        int move = 0;
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        
        while(!q.empty()){
            move++;
            int size = q.size();
            for(int i = 0; i < size;i++){
                string cur = q.front(); q.pop();    
                if (cur == endWord) return move;
                for(int pos = 0; pos < cur.size(); pos++){
                    string tmp(cur);
                    for(int c = 0; c < 26; c++){
                        tmp[pos] = 'a' + c;
                        if (tmp != cur && visited[tmp] == false && data.find(tmp) != data.end()){
                            q.push(tmp);
                            visited[tmp] = true;
                        }
                    }
                }
            }
        }
        return 0;
    }
};







//如果获取结果列表，难度就会大很多，这个时候bfs，可能因为过滤掉使用过的字符串，得到的结果是错误的
//126. Word Ladder II

//Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]

//dog-->log, dog-->cog, 这个时候log被设置已经访问过了，第二个结果不会得到

class Solution {
public:
    
    struct ListResult{
        vector<string> lists;
        string cur;
        ListResult(string v){
            cur = v;
        }
    };
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        if (wordList.size() == 0 || beginWord == endWord) return ret;
        
        set<string> data;
        for(auto& v : wordList){
            data.insert(v);
        }
        data.insert(beginWord);
        queue<ListResult> q;
        
        ListResult start(beginWord);
        start.lists.push_back(beginWord);
        q.push(start);
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size;i++){
                auto curNode = q.front(); q.pop();    
                if (curNode.cur == endWord){
                    ret.push_back(curNode.lists);
                    continue;
                }
                for(int pos = 0; pos < curNode.cur.size(); pos++){
                    string tmp(curNode.cur);
                
                    for(int c = 0; c < 26; c++){
                        tmp[pos] = 'a' + c;                        
                        if (tmp != curNode.cur && visited[tmp] == false && data.find(tmp) != data.end()){
                            ListResult next(tmp);
                            next.lists.assign(curNode.lists.begin(),curNode.lists.end());
                            next.lists.push_back(tmp);
                            q.push(next);
                            visited[tmp] = true;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
