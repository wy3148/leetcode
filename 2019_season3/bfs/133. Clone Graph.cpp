#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


//错误答案，如果用变量申明， 记得更新hashmap

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> oldNew;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*,bool> visited;
        visited[node] = true;
        
        while(!q.empty()){
            Node* n = q.front(); q.pop();
            Node* newNode = nullptr;
            if (oldNew.find(n)  == oldNew.end()){
                newNode = new Node();
                newNode->val = n->val;

                ///!!!! 设置回去
                oldNew[n] = newNode;
            }else{
               newNode = oldNew[n]; 
            }
            
            for(auto cur : n->neighbors){
                Node* nb = nullptr;
                if (oldNew.find(cur) == oldNew.end()){
                    nb = new Node();
                    nb->val = cur->val;
                }else{
                    nb = oldNew[cur];
                }
                newNode->neighbors.push_back(nb);
                
                if (visited[cur] == false){
                    q.push(cur);
                    visited[cur] = true;
                }
            }
        }
        return oldNew[node];
    }
};





/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> nodemap;
        queue<Node*> q;
        q.push(node);
        
        unordered_map<Node*,bool> visited;
        visited[node] = true;
        
        while(!q.empty()){
            Node* n = q.front(); q.pop();
            Node* cloned = nullptr;
            if (nodemap.find(n) == nodemap.end()){
                cloned = new Node();
                cloned->val = n->val;
                nodemap[n] = cloned;
            }else{
                cloned = nodemap[n];
            }
            
            for(auto cur : n->neighbors){                
                if (nodemap.find(cur) == nodemap.end()){
                    nodemap[cur] = new Node(cur->val);
                    if (visited[cur] == false){
                        q.push(cur);
                        visited[cur] = true;
                    }
                }
                cloned->neighbors.push_back(nodemap[cur]);
            }
        }
        return nodemap[node];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> nodemap;
        queue<Node*> q;
        q.push(node);
        
        unordered_map<Node*,bool> visited;
        visited[node] = true;
        
        while(!q.empty()){
            Node* n = q.front(); q.pop();
            Node* cloned = nullptr;
            if (nodemap.find(n) == nodemap.end()){
                cloned = new Node();
                cloned->val = n->val;
                nodemap[n] = cloned;
            }else{
                cloned = nodemap[n];
            }
            
            for(auto cur : n->neighbors){                
                if (nodemap.find(cur) == nodemap.end()){
                    nodemap[cur] = new Node(cur->val);
                    if (visited[cur] == false){
                        q.push(cur);
                        visited[cur] = true;
                    }
                }
                cloned->neighbors.push_back(nodemap[cur]);
            }
        }
        return nodemap[node];
    }
};
