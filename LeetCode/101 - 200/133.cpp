// 133. Clone Graph
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// hashmap and DFS(recursion)
// Time Complexity : O(V + E)
// Space Complexity : O(V + E)
class Solution {
public:
    unordered_map <Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(mp.find(node) == mp.end()){
            mp[node] = new Node(node->val);
            for(auto n : node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(n));
            }
        }
        return mp[node];
    }
};

// Hashmap and BFS using queue
class Solution {
public:
    unordered_map <Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* result = new Node(node->val, {});
        mp[node] = result;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* n : curr->neighbors){
                if(mp.find(n) == mp.end()){
                    mp[n] = new Node(n->val, {});
                    q.push(n);
                }
                mp[curr]->neighbors.push_back(mp[n]);
            }
        }
        return result;
    }
};

